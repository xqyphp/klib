#ifndef k_buffer_h
#define k_buffer_h
#include "k_types.h"
#include "k_mpool.h"

typedef struct k_buffer_s {
	void*  data_ptr;
	size_t data_used;
	size_t data_len;
	k_mpool_t* pool;
}k_buffer_t;


void  k_buffer_init(k_buffer_t* buffer, k_mpool_t* pool, size_t init_size);
void  k_buffer_write(k_buffer_t* buffer, void* data_ptr, size_t data_len);
void  k_buffer_write_ch(k_buffer_t* buffer, char ch);
void* k_buffer_get_data(k_buffer_t* buffer);
void* k_buffer_get_len(k_buffer_t* buffer);

#endif
