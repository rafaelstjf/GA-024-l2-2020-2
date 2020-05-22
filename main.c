#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BTree.h"
#include "AVLTree.h"
#include "TrieTree.h"
void btree_test();
void avltree_test();
int main()
{
    /*TrieTree* t = NULL;
    trie_insert(&t, "astolfo");
    trie_insert(&t, "zatchbell");
    trie_insert(&t, "alonso");
    trie_insert(&t, "beckham");
    trie_insert(&t, "barathrum");

    trie_print(t);*/
    avltree_test();
    return 0;
}
void avltree_test()
{
    AVLTree *a = NULL;
    avltree_insert(&a, 5);
    avltree_insert(&a, 2);
    avltree_insert(&a, 7);
    avltree_insert(&a, 1);
    avltree_insert(&a, 4);
    avltree_insert(&a, 6);
    avltree_insert(&a, 9);
    avltree_insert(&a, 3);
    avltree_insert(&a, 16);
    //Savltree_insert(&a, 15);
    avltree_print(a);
    printf("------------\n");
    avltree_remove(&a, 7);
    avltree_print(a);
}
void btree_test()
{
    BTree *r = btree_createfrom(1, btree_createfrom(2, NULL, NULL), btree_createfrom(1, NULL, NULL));
    BTree *r_bin = NULL;
    r_bin = btree_insert(r_bin, 6);
    r_bin = btree_insert(r_bin, 7);
    r_bin = btree_insert(r_bin, 4);
    r_bin = btree_insert(r_bin, 5);
    r_bin = btree_insert(r_bin, 2);
    r_bin = btree_insert(r_bin, 7);
    r_bin = btree_insert(r_bin, 11);
    r_bin = btree_insert(r_bin, 23);
    r_bin = btree_insert(r_bin, 42);
    printf("Altura da arvore: %d\n", btree_height(r_bin));
    printf("Quantidade de nos folha: %d\n", btree_numleaves(r_bin));
    if (btree_issearchtree(r_bin))
        printf("Eh arvore binaria de busca!\n");
    else
        printf("Nao eh arvore binaria de busca!\n");
    if (btree_isavltree(r_bin))
        printf("Eh AVL !\n");
    else
        printf("Nao eh AVL!\n");
    btree_print(r_bin);
}