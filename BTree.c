#include "BTree.h"
struct btree
{
    int info;
    struct btree *sad;
    struct btree *sae;
};
int btree_height(BTree *t)
{
    if (t)
    {
        int left = 1 + btree_height(t->sae);
        int right = 1 + btree_height(t->sad);
        if (left > right)
            return left;
        else
            return right;
    }
    else
        return 0;
}
int btree_numleaves(BTree *t)
{
    if (t)
    {
        if (!t->sad && !t->sae)
            return 1;
        else
            return btree_numleaves(t->sae) + btree_numleaves(t->sad);
    }
    else
        return 0;
}
