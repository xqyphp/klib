#include "k_mpool.h"
#include "k_cstd.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

static int pool_block_get_free(block_t* block)
{
	int used = block->cur_pos - ((char*)block + sizeof(block_t));
	return block->mem_size - used;
}

static void pool_add_block(k_mpool_t* pool, block_t* block, int block_size)
{
	LOG("add block->index = %d , size = %d\n", block->debug_index, block_size);
	block->mem_size = block_size;
	block->cur_pos = ((char*)block) + sizeof(block_t);
	k_list_insert_after((k_list_t*)&(pool->blocks), (k_list_t*)block);
}


static block_t* pool_find_block(k_mpool_t* pool, int rq_size)
{
	block_t* block = (block_t*)pool->blocks.next;
	while ((void*)block != &(pool->blocks)) {
		block_t* block_next = (block_t*)block->next;
		int mem_free = pool_block_get_free(block);
		if (mem_free >= rq_size) {
			LOG("pool_find_block->index = %d , size = %d,free=%d\n", block->debug_index, block->mem_size, mem_free);
			return block;
		}
		block = block_next;
	}
	LOG("pool_find_block->null.\n");
	return NULL;
}

static block_t* pool_new_block(k_mpool_t* pool, int block_size)
{

	block_t* block = (block_t*)k_malloc(sizeof(block_t) + block_size);
	block->debug_index = pool->block_count++;
	pool_add_block(pool, block, block_size);

	LOG("pool_new_block->index = %d , size = %d.\n", block->debug_index, block->mem_size);

	return block;
}

k_mpool_t* k_mpool_create(const char* name, int init_size, int increase)
{
	LOG("pool_create -> %s,size=%d,increase=%d.\n", name, init_size, increase);
	k_mpool_t* pool = (k_mpool_t*)k_malloc(sizeof(k_mpool_t));
	assert(strlen(name) < POOL_NAME_LEN);
	strcpy(pool->pool_name, name);
	pool->init_size = init_size;
	pool->cur_size = init_size;
	pool->increase_size = increase;
	pool->block_count = 0;
	pool->current_block = NULL;
	k_list_init(&(pool->blocks));
	pool_new_block(pool, init_size);
	return pool;
}

void*   k_mpool_malloc(k_mpool_t*pool, int rq_size)
{
	LOG("pool_malloc -> rq_size=%d.\n", rq_size);
	block_t* block = pool_find_block(pool, rq_size);
	if (block == NULL) {
		block = pool_new_block(pool, pool->increase_size > rq_size ? pool->increase_size : rq_size);
		assert(block != NULL);
	}
	pool->current_block = block;
	void* ptr_mem = block->cur_pos;
	block->cur_pos += rq_size;
	LOG("pool_malloc return -> index =%d.\n", block->debug_index);
	return ptr_mem;
}

void*   k_mpool_malloc_fast(k_mpool_t* pool, int rq_size)
{
	LOG("pool_malloc_fast -> rq_size=%d.\n", rq_size);

	block_t* block = pool->current_block;
	if (block == NULL || pool_block_get_free(block) < rq_size) {
		block = pool_new_block(pool, pool->increase_size > rq_size ? pool->increase_size : rq_size);
		assert(block != NULL);
	}
	pool->current_block = block;
	void* ptr_mem = block->cur_pos;
	block->cur_pos += rq_size;
	LOG("pool_malloc return -> index =%d.\n", block->debug_index);
	return ptr_mem;
}

int     k_mpool_destory(k_mpool_t* pool)
{
	LOG("destory pool -> %s\n", pool->pool_name);
	block_t* block = (block_t*)pool->blocks.next;
	while ((void*)block != &(pool->blocks)) {
		block_t* block_next = (block_t*)block->next;
		LOG("free_block -> index =%d.\n", block->debug_index);
		k_free(block);
		block = block_next;
	}
	LOG("free_pool -> %s.\n", pool->pool_name);
	k_free(pool);
	return 1;
}