#include "Hash.h"
struct aluno
{
    char nome[81];
    int matricula;
    float cr;
    struct aluno *prox;
};

int hash(char *nome)
{
    if (nome)
    {
        int sum = 0;
        unsigned int i = 0;
        while (nome[i] != '\0')
        {
            sum += nome[i];
            i++;
        }
        return sum % N;
    }
    else
        return -1;
}
Registry *hash_get(Hash tab, char *nome)
{
    int index = hash(nome);
    if (index == -1)
        return NULL;
    Registry *it = tab[index];
    while (it && strcmp(it->nome, nome) != 0)
        it = it->prox;
    return it;
}
Registry *hash_put(Hash tab, char *nome, int mat, float cr)
{
    int index = hash(nome);
    if (index == -1)
        return tab[index];
    Registry *it = tab[index];
    Registry *ant = NULL;
    while (it && strcmp(it->nome, nome) != 0)
    {
        ant = it;
        it = it->prox;
    }
    if (it)
    {
        it->matricula = mat;
        it->cr = cr;
    }
    else
    {
        if (ant)
        {
            ant->prox = it;
            it = (Registry *)malloc(sizeof(Registry));
            strcpy(it->nome, nome);
            it->matricula = mat;
            it->cr = cr;
        }else{
            tab[index] = (Registry *)malloc(sizeof(Registry));
            strcpy(tab[index]->nome, nome);
            tab[index]->matricula = mat;
            tab[index]->cr = cr;
        }
    }
    return tab[index];
}
Registry *hash_remove(Hash tab, char *nome)
{
    int index = hash(nome);
    if (index == -1)
        return NULL;
    Registry *it = tab[index];
    Registry *ant = NULL;
    while (it && strcmp(it->nome, nome) != 0)
    {
        ant = it;
        it = it->prox;
    }
    if (it)
    {
        if (ant)
            ant->prox = NULL;
        else
        {
            ant = tab[index];
            tab[index] = NULL;
            return ant;
        }
        ant = it;
        it = NULL;
        return ant;
    }
    else
        return NULL;
}
int hash_print(Hash tab)
{
    for (unsigned int i = 0; i < N; i++)
    {
        Registry *it = tab[i];
        while (it)
        {
            printf("Indice: %d\n", i);
            printf("Nome: %s, Matricula: %d, Cr: %0.2f\n", tab[i]->nome, tab[i]->matricula, tab[i]->cr);
            it = it->prox;
        }
    }
}