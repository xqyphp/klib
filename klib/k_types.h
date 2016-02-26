//
//  types.h
//  klib
//
//  Created by LiKai on 16/1/8.
//  Copyright © 2016年 LiKai. All rights reserved.
//

#ifndef ktypes_h
#define ktypes_h

#include <stddef.h>
#include "k_cstd.h"

typedef unsigned       k_bool_t;
typedef int            k_status_t;
typedef unsigned int   k_size_t;

#define K_SUCCESS      0
#define K_ERROR       -1
#define K_TRUE         1
#define K_FALSE        0
#define K_NULL         ((void*)0)

typedef int            (*k_compare_t)(void* left,void* right);
typedef void*          (*k_getkey_t)(void* rbnode);

#define LOG(...) 
//#define LOG(...) printf(__VA_ARGS__)

#ifndef errno_t
typedef int            k_errno_t;
#else
typedef errno_t        k_errno_t;
#endif

#endif /* ktypes_h */
