#ifndef BTREE_H
#define BTREE_H
#include <stdio.h>
#include<stdlib.h>
typedef struct btree BTree;
BTree *btree_createfrom(int info, BTree *sae, BTree *sad);
BTree *btree_create(void);
BTree *btree_insert(BTree *t, int info);
int btree_height(BTree *t);
int btree_numleaves(BTree *t);
int btree_issearchtree(BTree *t);
int btree_isavltree(BTree *t);
BTree *btree_destroy(BTree *t);
void btree_print(BTree *t);

#endif