#ifndef AVLTREE_H
#define AVLTREE_H
#include <stdio.h>
#include <stdlib.h>
typedef struct avltree AVLTree;

//functions
int avltree_insert(AVLTree** t, int element);
void avltree_print(AVLTree* t);
int avltree_height(AVLTree* t);
#endif