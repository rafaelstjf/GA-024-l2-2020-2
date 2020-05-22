#ifndef TRIETREE_H
#define TRIETREE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct trietree TrieTree;

int trie_insert(TrieTree** t, char* element);
void trie_print(TrieTree *t);
#endif