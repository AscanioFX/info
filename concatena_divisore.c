/* VERSIONE VECCHIUCCIA E ABBASTANZA GREZZA MA FUNZIONANTE */

#include <stdio.h>
#include <stdlib.h>
#define DIM 4

void stampaV(int v[], int dim){
    int i;
    for (i=0; i<dim; i++)
        printf("%i ", v[i]);

    printf("\n");
}

int un_solo_comune(int a, int b){
    int i;
    int div_com = 0;

    for (i=2; i<(a>b?a:b); i++){
        if (a % i == 0 && b % i == 0)
            div_com++;
        if (div_com > 1)
            return 0;
    }
if (div_com == 0)
    return 0;
return 1;
}

int controlla_catena(int catena[], int dim){
    int i = 0;
    int contatore = 0;
    for (i=0; i<dim-1; i++){
        if (un_solo_comune(catena[i], catena[i+1]) == 0){
            return i+1;;
        }
    }
    return i+1;
}

int *vettDup(int *vett, int dim)
{
    int *ptr = malloc(sizeof(int)*dim);
    int i;
    for (i=0; i<dim; i++)
    {
        ptr[i] = vett[i];
    }
    return ptr;
}

int *permutazioni(int a[], int b[], int  dim, int *vincente){
    int i=0, j;
    int tempA;
    int len = controlla_catena(b, dim);
    int max = controlla_catena(vincente, dim);
    while (b[i] != 0 && i<dim)
        i++;

    if (i == dim){
       if (len > max)
       {
           vincente = vettDup(b, dim);
       }
        return vincente;
    }
    for (j=0; j<dim; j++){
        if (a[j] != 0){
            tempA = a[j];
            b[i] = a[j];
            a[j] = 0;
            vincente = permutazioni(a, b, dim, vincente);
            a[j] = tempA;
            b[i] = 0;
        }
    }
    return vincente;
}

int *soluzione(int a[], int dim)
{
    int b[dim];
    int c[dim];
    int i;
    for (i=0; i<dim; i++)
    {
        b[i] = 0;
        c[i] = 0;
    }
    return permutazioni(a, b, dim, c);
}

void stampaSoluz(int a[], int dim)
{
    int i;
    int max = controlla_catena(a, dim);

    for (i=0; i<max; i++)
        printf("%i ", a[i]);
    printf("\tPunteggio: %i\n", max);
}


int main(){
    int a[] = {8,3,14,6};
    int dim = 4;
    int *soluz = soluzione(a,dim);
    stampaSoluz(soluz, dim);
    return 0;
}
