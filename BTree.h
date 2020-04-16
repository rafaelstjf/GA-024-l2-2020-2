#ifndef BTREE_H
#define BTREE_H
typedef struct btree BTree;
int btree_height(BTree *t);
int btree_numleaves(BTree *t);
#endif