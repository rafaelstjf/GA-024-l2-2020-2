#ifndef HASH_H
#define HASH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 193
typedef struct aluno Registry;
typedef Registry *Hash[N];
int hash(char* nome);
Registry *hash_get(Hash tab, char* nome);
int hash_print(Hash tab);
Registry *hash_put(Hash tab, char* nome, int mat, float cr);
Registry *hash_remove(Hash tab, char* nome);
#endif