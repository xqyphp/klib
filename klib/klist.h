//
//  list.h
//  klib
//
//  Created by LiKai on 16/1/8.
//  Copyright © 2016年 LiKai. All rights reserved.
//

#ifndef klist_h
#define klist_h

#include "ktypes.h"

#define DEF_LIST_HEAD(list_type) \
    list_type* prev; \
    list_type* next

typedef struct klist_s{
    DEF_LIST_HEAD(struct klist_s);
}klist_t;

void
klist_init(klist_t* klist);

void
klist_link(klist_t* prev, klist_t* next);

void
klist_insert_before(klist_t* pos,klist_t* val);

void
klist_insert_after(klist_t* pos,klist_t* val);

#endif /* klist_h */
