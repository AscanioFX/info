#include <stdio.h>
#define DIM 4

void stampaV(int v[], int dim){
    int i, j;
    for (i=0; i<dim; i++){
        printf("%i ", v[i]);
    }
    printf("\n");
}

/* a = array da permutare, b = array di 0 sul quale costruisce la permutazione */
int  permutazioni(int a[],int b[], int dim){
    int i=0, j;
    int tempA;


    while (b[i] != 0 && i<dim)
        i++;
    if (i == dim){
        stampaV(b, dim);
        return 1;
    }
    for (j=0; j<dim; j++){
        if (a[j] != 0){
            tempA = a[j];
            b[i] = a[j];
            a[j] = 0;
            permutazioni(a, b, dim);
            a[j] = tempA;
            b[i] = 0;
        }
    }
  return 1;

}


void test(){
    int a[] = {1,2,3,4};
    int b[] = {0,0,0,0};

    permutazioni(a, b, 4);

}



int main(){
    test();
    return 0;
}
