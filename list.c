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

/* Esempio di append senza ritorno. Riceve l'indirizzo del puntatore alla lista, e la parola da appendere. */
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

/* Esempio di append senza ritorno. Se disponibile accetta un puntatore all'ultimo elemento, altrimenti NULL */
void listAppend(node** list, char* parola, node** last)
{
    if(*last != NULL)
    {
        (*last)->next = malloc(sizeof(node));
        *last = (*last)->next;
        (*last)->parola = strdup(parola);
        (*last)->next = NULL;
    } else if (*list == NULL)
    {
        *list = malloc(sizeof(node));
        (*list)->parola = strdup(parola);
        (*list)->next = NULL;
        *last = *list;
    } else
    {
        listAppend(&((*list)->next), parola, last);
    }
}
/* Confronta 2 parole e ritorna 1 se sono i ordine alfabetico, altrimenti 0 */
int alfabetico(char* s1, char* s2)
{
    int dim1 = strlen(s1);
    int dim2 = strlen(s2);
    int i;

    for (i=0; i<(dim1 > dim2 ? dim1 : dim2); i++)
    {
        if (s1[i] > s2[i])
            return 0;
        else if (s1[i] < s2[i])
            return 1;
    }
    if (dim1 > dim2)
        return 0;
    return 1;
}

/* Ordina la lista. Si suppone alfabetico ordini in ordine alfabetico */
void listSort(nodo* lista)
{
    nodo* temp = lista;
    nodo* swap;
    nodo* successiv;
    int flag = 0;
    while (flag == 0)
    {
        while (temp->prossimo != NULL)
        {
            if (alfabetico(temp->parola, temp->prossimo->parola) == 0)
                {
                    successivo = temp->prossimo;
                    swap = temp;
                }
        }
    }
}

/* Esempio di funzione per acquisire le parole da file e metterle in una lista */
node* insertParole(char* nomeFile)
{
    printf("Inizio acquisizione dizionario.\n");
    FILE* f = fopen(nomeFile, "r");
    char buffer[30];
    node* list = NULL;
    node *last = NULL;

    while(!feof(f))
    {
        fscanf(f, "%s", buffer);
        listAppend(&list, buffer, &last);
    }
    printf("Finita acquisizione dizionario.\n");
    return list;
}

/* Se la parola è presente nella lista ritorna 1 , altrimenti 0 */
int presente(node* list, char* s)
{
    node* tmp = list;
    while (tmp != NULL)
    {
        if (strcmp(tmp->parola, s) == 0)
        {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}
