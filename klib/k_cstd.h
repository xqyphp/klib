#ifndef k_cstd_h
#define k_cstd_h

void*	k_calloc(int num_elems, int elem_size);
void	k_free(void *p);
void*	k_malloc(unsigned int num_bytes);
void*	k_realloc(void *mem_address, unsigned int newsize);

#endif
