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

/* Ritorna un puntatore all'ultimo elemento */
node* listLast(node* list)
{
    if (list == NULL)
    {
        printf("ERRORE [listLast] :: Lista vuota\n");
        return NULL;
    }
    else
    while (list->next != NULL)
        list = list->next;

    return list;
}

/* Ritorna la lunghezza della lista */
int listLen(node* list){
    int i, dim = 0;

    while (list != NULL)
    {
        list = list->next;
        dim++;
    }
    return dim;
}

/* Esempio di append senza ritorno. Riceve l'indirizzo del puntatore alla lista, e l'elemento da appendere. */
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
