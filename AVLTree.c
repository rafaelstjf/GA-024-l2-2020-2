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
        if (t->sad && t->sae)
        {
            return (t->sad->height - t->sae->height);
        }
        else if (t->sad && !t->sae)
            return t->sad->height;
        else if (!t->sad && t->sae)
            return (-1) * t->sae->height;
        else
            return 0;
    }
    return 0;
}
static void ll_rotation(AVLTree* t){
    AVLTree* t1 = t->sae;
    //troca os valores
    int temp_val = t->info;
    t->info = t1->info;
    t1->info = temp_val;
    //faz com que a arvore a esquerda da raiz seja a arvore a esquerda do novo pivo
    t->sae = t1->sae;
    //a sad do pivo vira a sae
    t1->sae = t1->sad;
    //a sad do pivo vira a sad da raiz
    t1->sad = t->sad;
    //atualiza a altura
    t->height = (t->sad->height > t->sae->height) ? t->height = t->sad->height : t->sae->height;
    //a sad da raiz vira o pivo
    t->sad = t1;
}
static void rr_rotation(AVLTree* t){
    AVLTree* t1 = t->sad;
    //troca os valores
    int temp_val = t->info;
    t->info = t1->info;
    t1->info = temp_val;
    //faz com que a arvore a esquerda da raiz seja a arvore a esquerda do novo pivo
    t->sad = t1->sad;
    //a sad do pivo vira a sae
    t1->sad = t1->sae;
    //a sad do pivo vira a sad da raiz
    t1->sae = t->sae;
    //atualiza a altura
    t->height = (t->sad->height > t->sae->height) ? t->height = t->sad->height : t->sae->height;
    //a sad da raiz vira o pivo
    t->sae = t1;
}
static void lr_rotation(AVLTree* t){

}
static void rl_rotation(AVLTree* t){

}
int avltree_insert(AVLTree *t, int element)
{
    if (t)
    {
        if (t->info < element)
        {
            if (!avltree_insert(t->sae, element))
                return 0;
        }
        else if (t->info > element)
            if (!avltree_insert(t->sad, element))
                return 0;
        if (t->sae && t->sad)
        {
            if (t->sad->height > t->sae->height)
                t->height = t->sad->height;
            else
                t->height = t->sae->height;
        }
        else if (!t->sae)
            t->height = t->sad->height;
        else
            t->height = t->sae->height;
        int fb_t = calc_fb(t);
        int fb_tsae = calc_fb(t->sae);
        int fb_tsad = calc_fb(t->sad);
        if (abs(fb_t) == 2)
        {
            if (abs(fb_tsad) == 1)
            {
                if (fb_t * fb_tsad > 0)
                {
                    ll_rotation(t);
                }
                else
                {
                    //chama rotacao lr
                }
            }
            else if (abs(fb_tsae) == 1)
            {
                if (fb_t * fb_tsae > 0)
                {
                    rr_rotation(t);
                }
                else
                {
                    //chama rotacao rl
                }
            }
        }
        return 1;
    }
    else
    {
        t = (AVLTree *)malloc(sizeof(AVLTree));
        if (!t)
            return 0;
        t->info = element;
        t->sad = NULL;
        t->sae = NULL;
        t->height = 0;
        return 1;
    }
}
void avltree_print(AVLTree* t){
    if(t){
        printf("%d", t->info);
        if(t->sae) printf(" sae: %d", t->sae->info);
        if(t->sad) printf(" sad: %d", t->sad->info);
        printf("\n");
        avltree_print(t->sae);
        avltree_print(t->sad);
    }
}