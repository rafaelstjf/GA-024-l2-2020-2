#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BTree.h"
int main()
{
    BTree *r = btree_createfrom(1, btree_createfrom(2, NULL, NULL), btree_createfrom(1, NULL, NULL));
    BTree *r_bin = NULL;
    r_bin = btree_insert(r_bin, 6);
    r_bin = btree_insert(r_bin, 7);
    r_bin = btree_insert(r_bin, 4);
    r_bin = btree_insert(r_bin, 5);
    r_bin = btree_insert(r_bin, 2);
    printf("Altura da arvore: %d\n", btree_height(r_bin));
    printf("Quantidade de nos folha: %d\n", btree_numleaves(r_bin));
    if(btree_issearchtree(r_bin)) printf("Eh arvore binaria de busca!\n");
    else printf("Nao eh arvore binaria de busca!\n");
    if(btree_isavltree(r_bin)) printf("Eh AVL !\n");
    else printf("Nao eh AVL!\n");
    btree_print(r);
    return 0;
}
