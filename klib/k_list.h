//
//  list.h
//  klib
//
//  Created by LiKai on 16/1/8.
//  Copyright © 2016年 LiKai. All rights reserved.
//

#ifndef k_list_h
#define k_list_h

#include "k_types.h"

#define DEF_LIST_HEAD(list_type) \
    list_type* prev; \
    list_type* next

typedef struct k_list_s{
    DEF_LIST_HEAD(struct k_list_s);
}k_list_t;

void
k_list_init(k_list_t* k_list);

void
k_list_link(k_list_t* prev, k_list_t* next);

void
k_list_insert_before(k_list_t* pos,k_list_t* val);

void
k_list_insert_after(k_list_t* pos,k_list_t* val);

void
k_list_remove(k_list_t* pos);

#endif /* k_list_h */
