//
//  k_list.c
//  klib
//
//  Created by LiKai on 16/1/8.
//  Copyright © 2016年 LiKai. All rights reserved.
//

#include "k_list.h"

void
k_list_init(k_list_t* k_list)
{
     k_list->prev = k_list;
     k_list->next = k_list;
}

void
k_list_link(k_list_t* prev, k_list_t* next)
{
     prev->next = next;
     next->prev = prev;
}

void
k_list_insert_before(k_list_t* pos,k_list_t* val)
{
     k_list_t* list_temp = pos->prev;
     k_list_link(list_temp,val);
     k_list_link(val,pos);
}

void
k_list_insert_after(k_list_t* pos,k_list_t* val)
{
     k_list_insert_before(pos->next,val);
}

k_list_t*
k_list_remove(k_list_t* pos)
{
     k_list_link(pos->prev,pos->next);
     return pos;
}

