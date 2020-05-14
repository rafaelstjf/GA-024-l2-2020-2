#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BTree.h"
int main(){
    BTree* r = btree_createfrom(1, btree_createfrom(2, NULL, NULL), btree_createfrom(1, NULL, NULL));
    BTree* r_bin = NULL;
    for(unsigned int i = 0; i < 10; i++)
        r_bin = btree_insert(r_bin, i);
    printf("Altura da arvore: %d\n", btree_height(r_bin));
    btree_print(r);
    return 0;
}
