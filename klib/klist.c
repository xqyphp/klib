//
//  klist.c
//  klib
//
//  Created by LiKai on 16/1/8.
//  Copyright © 2016年 LiKai. All rights reserved.
//

#include "klist.h"

void
klist_init(klist_t* klist)
{
     klist->prev = klist;
     klist->next = klist;
}

void
klist_link(klist_t* prev, klist_t* next)
{
     prev->next = next;
     next->prev = prev;
}

void
klist_insert_before(klist_t* pos,klist_t* val)
{
     klist_t* list_temp = pos->prev;
     klist_link(list_temp,val);
     klist_link(val,pos);
}

void
klist_insert_after(klist_t* pos,klist_t* val)
{
     klist_insert_before(pos->next,val);
}
