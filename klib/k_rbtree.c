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

static void
right_rotate(k_rbtree_t* t,k_rbnode_t* y)
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
k_rbtree_init(k_rbtree_t* rbtree,k_compare_t compare,
	      k_getkey_t getkey)
{
     rbtree->compare = compare;
     rbtree->getkey  = getkey;
     rbtree->nil_node= K_NULL;
     rbtree->root = rbtree->nil_node;
     rbtree->left = rbtree->nil_node;
     rbtree->right= rbtree->nil_node;
}

static void
k_rbtree_insert_fixup(k_rbtree_t* t,k_rbnode_t* z)
{
     k_rbnode_t* y = K_NULL;
     while(z->parent->color == k_color_red)
     {
	  if(z->parent == z->parent->parent->left)
	  {
	       y = z->parent->parent->right;
	       if(y->color == k_color_red)//case 1
	       {
		    z->parent->color = k_color_black;
		    y->color = k_color_black;
		    z->parent->parent->color = k_color_red;
		    z = z->parent->parent;
	       }else{
		    if(z == z->parent->right){//case 2
			 z = z->parent;
			 left_rotate(t,z);
		    }
		    //case 2 will turn to case 3
		    z->parent->color = k_color_black;//case 3
		    z->parent->parent->color = k_color_red;
		    right_rotate(t,z->parent->parent);
		    
	       }
	       
	  }else{
	       y = z->parent->parent->left;
	       if(y->color == k_color_red)//case 1
	       {
		    z->parent->color = k_color_black;
		    y->color = k_color_black;
		    z->parent->parent->color = k_color_red;
		    z = z->parent->parent;
	       }else{
		    if(z == z->parent->left){//case 2
			 z = z->parent;
			 right_rotate(t,z);
		    }
		    
		    z->parent->color = k_color_black;//case 3
		    z->parent->parent->color = k_color_red;
		    left_rotate(t,z->parent->parent);
	       }

	  }
     }
     t->root->color = k_color_black;
}

void
k_rbtree_insert(k_rbtree_t* t,k_rbnode_t* z)
{
     k_rbnode_t* y = t->nil_node;
     k_rbnode_t* x = t->root;

     while(x != t->nil_node)
     {
	  y = x;
	  if(t->compare(t->getkey(z),t->getkey(x)) < 0)
	  {
	       x = x->left;
	  }else{
	       x = x->right;
	  }
     }
     z->parent = y;
     if(y == t->nil_node)
     {
	  t->root = z;
     }else if(t->compare(t->getkey(z),t->getkey(y)) < 0){
	  y->left = z;
     }else{
	  y->right = z;
     }

     z->left = t->nil_node;
     z->right = t->nil_node;
     z->color = k_color_red;
     k_rbtree_insert_fixup(t,z);
}
