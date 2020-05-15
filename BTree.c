#include "BTree.h"
struct btree
{
    int info;
    struct btree *sad;
    struct btree *sae;
};
typedef struct fila
{
    struct btree *el;
    struct fila *next;
} Fila;
static Fila *fila_add(Fila *f, BTree *t)
{
    if (f)
    {
        Fila *n = (Fila *)malloc(sizeof(Fila));
        n->el = t;
        n->next = NULL;
        f->next = n;
    }
    else
    {
        f = (Fila *)malloc(sizeof(Fila));
        f->el = t;
        f->next = NULL;
    }
    return f;
}
static Fila *fila_remove(Fila *f)
{
    if (f)
    {
        return f->next;
    }
    else
        return NULL;
}
static BTree *fila_veprimeiro(const Fila *f)
{
    if (f)
    {
        return f->el;
    }
    else
        return NULL;
}
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
    else if(info > t->info)
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
            if (t->sae->info < t->info)
                left = btree_issearchtree(t->sae);
            else
                return 0;
        }
        int right = 1;
        if (t->sad)
        {
            if (t->sad->info > t->info)
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
    if (t)
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
        for (int i = 0; i < spc / 2; i++)
            printf(" ");
        if (t->sae)
            printf("%d", t->sae->info);
        for (int i = 0; i < spc; i++)
            printf(" ");
        if (t->sad)
            printf("%d", t->sad->info);
        printf("\n");

        print_aux(t->sae, spc / 2);
        print_aux(t->sad, spc);
    }
}
void btree_print(BTree *t)
{
    int height = btree_height(t);
    Fila *f = NULL;
    if (t)
        f = fila_add(f, t);
    while (f)
    {
        Fila *itf = f;
        Fila *f2 = NULL;
        while (f)
        {
            BTree *it = fila_veprimeiro(f);
            for (int i = 0; i < height; i++)
                printf(" ");
            printf("%d", it->info);
            if (it->sae)
                f2 = fila_add(f2, it->sae);
            if (it->sad)
                f2 = fila_add(f2, it->sad);
            f = fila_remove(f);
        }
        height = ceil((float)height / 2);
        printf("\n");
        while (f2)
        {
            f = fila_add(f, fila_veprimeiro(f2));
            f2 = fila_remove(f2);
        }
    }
}
