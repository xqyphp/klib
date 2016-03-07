#ifndef ktypes_h
#define ktypes_h

#include <stddef.h>
#include <errno.h>

#include "k_cstd.h"

typedef unsigned int   k_size_t;

typedef enum k_bool_enum{
	K_FALSE = 0,
	K_TRUE  = 1
}k_bool_t;

typedef enum k_status_enum {
	K_SUCCESS = 0,
	K_ERROR = -1
}k_status_t;

#define K_NULL         ((void*)0)

typedef int            (*k_compare_t)(void* left,void* right);
typedef void*          (*k_getkey_t)(void* rbnode);

#define LOG(...) 
//#define LOG(...) printf(__VA_ARGS__)

typedef int        k_errno_t;

#endif /* ktypes_h */
