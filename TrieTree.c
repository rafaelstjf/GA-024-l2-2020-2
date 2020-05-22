#include "TrieTree.h"

struct trietree
{
    char *value;
    struct trietree *links[26];
};
int insert_aux(TrieTree **t, char *element, int ind)
{

    if (!(*t))
    {
        (*t) = (TrieTree *)malloc(sizeof(TrieTree));
        (*t)->value = NULL;
        for (unsigned int i = 0; i < 26; i++)
            (*t)->links[i] = NULL;
    }
    if (ind < (strlen(element)))
    {
        unsigned int index = element[ind] - 97;
        if (index < 0 || index >= 26)
            return 0;
        if (!insert_aux(&(*t)->links[index], element, ind + 1))
            return 0;
    }
    else
    {
        if (!(*t)->value)
        {
            (*t)->value = (char *)malloc(sizeof(char) * (strlen(element) + 1));
            strcpy((*t)->value, element);
            return 1;
        }
        else
            return 0;
    }
}
void trie_print(TrieTree *t)
{
    if (t)
    {
        if (t->value)
            printf("%s\n", t->value);
        for (unsigned int i = 0; i < 26; i++)
        {
            if (t->links[i])
            {
                trie_print(t->links[i]);
            }
        }
    }
}
int trie_insert(TrieTree **t, char *element)
{
    insert_aux(t, element, 0);
}
