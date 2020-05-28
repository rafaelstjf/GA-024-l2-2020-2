#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BTree.h"
#include "AVLTree.h"
#include "TrieTree.h"
#include "Hash.h"
void btree_test();
void avltree_test();
void trietree_test();
void hash_test();
int main()
{
   
    hash_test();
    return 0;
}
void hash_test(){
    Hash h;
    for(unsigned int i = 0; i < N; i++){
        h[i] = NULL;
    }
    h[hash("cleiton")] = hash_put(h, "cleiton", 20, 0.1);
    Registry* r = hash_get(h, "cleiton");
    if(r) printf("encontrou o cleitinho!\n");
    hash_print(h);
}
void trietree_test(){
    printf("Teste arvore trie\n");
    TrieTree* t = NULL;
    trie_insert(&t, "astolfo");
    trie_insert(&t, "zatchbell");
    trie_insert(&t, "alonso");
    trie_insert(&t, "beckham");
    trie_insert(&t, "barathrum");
    trie_print(t);
    printf("-----------------------------------\n");
}
void avltree_test()
{
    printf("Teste arvore avl\n");
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
    printf("######################\n");
    avltree_remove(&a, 7);
    avltree_print(a);
    printf("-----------------------------------\n");
}
void btree_test()
{
    printf("Teste arvore binaria\n");
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
    printf("-----------------------------------\n");
}