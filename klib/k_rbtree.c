//
//  rbtree.c
//  klib
//
//  Created by LiKai on 16/1/9.
//  Copyright © 2016年 LiKai. All rights reserved.
//

#include "k_rbtree.h"

static void
left_rotate(k_rbtree_t* t,k_rbnode_t* x)
{
    k_rbnode_t* y = x->right;
    x->right = y->left;
    if(y->left != t->nil_node)
    {
        y->left->parent = x;
    }
    
    y->parent = x->parent;
    if(x->parent == t->nil_node)
    {
        t->root = y;
    }else if(x->parent->left == x)
    {
        x->parent->left = y;
    }else if(x->parent->right == x){
        x->parent->right = y;
    }
    
    y->left = x;
    x->parent = y;
}

static void right_rotate(k_rbtree_t* t,k_rbnode_t* y)
{
    k_rbnode_t* x = y->left;
    
    y->left = x->right;//put x's right node to y's left node
    if(x->right != t->nil_node)
    {
	x->right->parent = y;
    }
    
    x->parent = y->parent;//link y->parent to x
    if(x->parent == t->nil_node)
    {
        t->root = x;
    }else if(y->parent->left == y){
        y->parent->left = x;
    }else if(y->parent->right == y){
        y->parent->right = x;
    }
    
    x->right = y;//put y to x's right
    y->parent = x;
}

void
k_rbtree_init(k_rbtree_t* rbtree,k_compare_t compare)
{
     
}
