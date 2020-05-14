#include "BTree.h"
struct btree
{
    int info;
    struct btree *sad;
    struct btree *sae;
};
static int btree_isempty(BTree *t)
{
    if (!t)
        return 1;
    else
        return 0;
}
BTree *btree_createfrom(int info, BTree *sae, BTree *sad)
{
    BTree *p = (BTree *)malloc(sizeof(BTree));
    p->info = info;
    p->sae = sae;
    p->sad = sad;
    return p;
}
BTree *btree_insert(BTree *t, int info)
{
    if (btree_isempty(t))
    {
        t = (BTree *)malloc(sizeof(BTree));
        t->info = info;
        t->sae = t->sad = NULL;
    }
    else if (info < t->info)
        t->sae = btree_insert(t->sae, info);
    else
        t->sad = btree_insert(t->sad, info);
    return t;
}

int btree_height(BTree *t)
{
    if (t)
    {
        int left = btree_height(t->sae);
        int right = btree_height(t->sad);
        if (left > right)
            return 1 + left;
        else
            return 1 + right;
    }
    else
        return -1;
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
int btree_issearchtree(BTree *t)
{
    if (t)
    {
        int left = 1;
        if (t->sae)
        {
            if (t->sae->info <= t->info)
                left = btree_issearchtree(t->sae);
            else
                return 0;
        }
        int right = 1;
        if (t->sad)
        {
            if (t->sad->info >= t->info)
                right = btree_issearchtree(t->sad);
            else
                return 0;
        }
        if (left <= right)
            return left;
        else
            return right;
    }
    else
        return 1;
}
int btree_isavltree(BTree *t)
{
    if (t)
    {
        int height_left = btree_height(t->sae);
        int height_right = btree_height(t->sad);
        if (abs(height_right - height_left) <= 1)
        {
            int r = btree_isavltree(t->sad);
            int l = btree_isavltree(t->sae);
            if (r <= l)
                return r;
            else
                return l;
        }
        else
            return 0;
    }
    else
        return 1;
}
BTree *btree_destroy(BTree *t)
{
    if (!btree_isempty(t))
    {
        btree_destroy(t->sae);
        btree_destroy(t->sad);
        free(t);
    }
    return NULL;
}
static void print_aux(BTree *t, int spc)
{
    if (t)
    {
        for (int i = 0; i < spc; i++)
            printf(" ");
        printf("%d", t->info);
        printf("\n");
        print_aux(t->sae, spc / 2);
        print_aux(t->sad, spc / 2);
    }
}
void btree_print(BTree *t)
{
    print_aux(t, btree_height(t));
}