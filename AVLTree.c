#include "AVLTree.h"

struct avltree
{
    int info;
    struct avltree *sad;
    struct avltree *sae;
    int height;
};
static int calc_fb(AVLTree *t)
{
    if (t)
    {
        int right = 0;
        int left = 0;
        if (t->sad)
            right = t->sad->height;
        if (t->sae)
            left = t->sae->height;
        return (right - left);
    }
    return 0;
}
int avltree_height(AVLTree *t)
{
    if (t)
    {
        int left = avltree_height(t->sae);
        int right = avltree_height(t->sad);
        if (left > right)
        {
            t->height = 1 + left;
            return 1 + left;
        }
        else
        {
            t->height = 1 + right;
            return 1 + right;
        }
    }
    else
        return -1;
}
static void r_rotation(AVLTree **t)
{
    printf("right rotation\n");
    AVLTree *t1 = (*t)->sae;
    //troca os valores
    int temp_val = (*t)->info;
    (*t)->info = t1->info;
    t1->info = temp_val;
    //faz com que a arvore a esquerda da raiz seja a arvore a esquerda do novo pivo
    (*t)->sae = t1->sae;
    //a sad do pivo vira a sae
    t1->sae = t1->sad;
    //a sad do pivo vira a sad da raiz
    t1->sad = (*t)->sad;
    //atualiza a altura
    int r_h = 0;
    int l_h = 0;
    if ((*t)->sad)
        r_h = (*t)->sad->height;
    if ((*t)->sae)
        l_h = (*t)->sae->height;
    (*t)->height = (r_h > l_h) ? r_h : l_h; //a sad da raiz vira o pivo
    (*t)->sad = t1;
}
static void l_rotation(AVLTree **t)
{
    printf("left rotation\n");
    AVLTree *t1 = (*t)->sad;
    //troca os valores
    int temp_val = (*t)->info;
    (*t)->info = t1->info;
    t1->info = temp_val;
    //faz com que a arvore a esquerda da raiz seja a arvore a esquerda do novo pivo
    (*t)->sad = t1->sad;
    //a sad do pivo vira a sae
    t1->sad = t1->sae;
    //a sad do pivo vira a sad da raiz
    t1->sae = (*t)->sae;
    //atualiza a altura
    int r_h = 0;
    int l_h = 0;
    if ((*t)->sad)
        r_h = (*t)->sad->height;
    if ((*t)->sae)
        l_h = (*t)->sae->height;
    (*t)->height = (r_h > l_h) ? r_h : l_h;
    //a sad da raiz vira o pivo
    (*t)->sae = t1;
}
int avltree_insert(AVLTree **t, int element)
{
    if (*t)
    {
        if ((*t)->info > element)
        {
            if (!avltree_insert(&((*t)->sae), element))
                return 0;
        }
        else if ((*t)->info < element)
            if (!avltree_insert(&((*t)->sad), element))
                return 0;
        (*t)->height = avltree_height(*t);
        int fb_t = calc_fb(*t);
        int fb_tsae = calc_fb((*t)->sae);
        int fb_tsad = calc_fb((*t)->sad);
        if (abs(fb_t) == 2)
        {
            if (abs(fb_tsad) == 1)
            {
                if (fb_t * fb_tsad > 0)
                {
                    //right-right case
                    printf("right-right case on %d\n", (*t)->info);
                    avltree_print(*t);
                    l_rotation(t);
                }
                else
                {
                    //Right-Left case
                    printf("right-left case on %d\n", (*t)->info);
                    avltree_print(*t);
                    r_rotation(&(*t)->sad);
                    l_rotation(t);
                }
            }
            else if (abs(fb_tsae) == 1)
            {
                if (fb_t * fb_tsae > 0)
                {
                    //left-left case
                    printf("left-left case on %d\n", (*t)->info);
                    avltree_print(*t);
                    r_rotation(t);
                }
                else
                {
                    //left-right case
                    printf("left-right case on %d\n", (*t)->info);
                    avltree_print(*t);
                    l_rotation(&(*t)->sae);
                    r_rotation(t);
                }
            }
        }
        return 1;
    }
    else
    {
        *t = (AVLTree *)malloc(sizeof(AVLTree));
        if (!t)
            return 0;
        (*t)->info = element;
        (*t)->sad = NULL;
        (*t)->sae = NULL;
        (*t)->height = 0;
        return 1;
    }
}
void avltree_print(AVLTree *t)
{
    if (t)
    {
        printf("%d", t->info);
        if (t->sae)
            printf(" sae: %d", t->sae->info);
        if (t->sad)
            printf(" sad: %d", t->sad->info);
        printf("\n");
        avltree_print(t->sae);
        avltree_print(t->sad);
    }
}