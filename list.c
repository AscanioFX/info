#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char* parola;
    struct node* next;
};

typedef struct node node;

/* Stampa una lista. Riceve il puntatore a lista */
void listPrint(node* parole)
{
    node* temp = parole;
    if (temp == NULL)
        printf("Lista vuota!\n");
    else
    {
        while (temp != NULL)
        {
            printf("%s\t", temp->parola);
            temp = temp->next;
        }
        printf("\n");
    }
}

void listAppend(node** list, char* parola)
{
    if (*list == NULL)
    {
        *list = malloc(sizeof(node));
        (*list)->parola = strdup(parola);
        (*list)->next = NULL;
    } else
    {
        listAppend(&((*list)->next), parola);
    }
}
