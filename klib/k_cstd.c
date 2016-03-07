#include "k_cstd.h"

#include <stdlib.h>

void *k_calloc(int num_elems, int elem_size)
{
	return calloc(num_elems, elem_size);
}

void k_free(void *p)
{
	 free(p);
}

void *k_malloc(unsigned int num_bytes)
{
	return malloc(num_bytes);
}

void *k_realloc(void *mem_address, unsigned int newsize)
{
	return realloc(mem_address, newsize);
}