#ifndef AVLTREE_H
#define AVLTREE_H
#include <stdio.h>
#include <stdlib.h>
#include "Btree.h"
typedef struct avltree AVLTree;

//functions
int avltree_insert(AVLTree* t, int element);
void avltree_print(AVLTree* t);

#endif