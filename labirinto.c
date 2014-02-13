#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* SQUADRA 3.4
 * Federico Reppucci
 * Ilaria Salbe
 * Marco Wenzel
 * Andrea Re Fraschini
 * Ascanio Vimercati Sanseverino
 * Sara Zanzottera
 */


/* Creo una mia funzione strdup pechè codelab impazzisce */
char *miastrdup(char *s)
{
    int i;
    int dim = strlen(s);
    char *t = malloc(sizeof(char)*(dim+1));

    for (i=0; i<dim; i++)
        t[i] = s[i];
    t[dim+1] = '\0';
    return t;
}


char* toLower(char* parola){
    int i;
    int aggiunta=(int)'A'-(int)'a';
    unsigned long dimensione=strlen(parola);

    /*Copio la stringa in una nuova e modifico quella*/
    char* tmp=(char*)malloc((dimensione+1)*sizeof(char));
    strcpy(tmp,parola);

    for(i=0;i<dimensione;i++){
        if(tmp[i]>='A' && tmp[i]<='Z')
            tmp[i]-=aggiunta;
    }
    tmp[i]=0;
    return tmp;
}




int trovaLunghezza(char *nomeFile){
    FILE*f=fopen(nomeFile,"r");
    char buffer[30];
    int i=0;
    while(!feof(f)){
        int m=fscanf(f,"%s",buffer);
        if(m>0){
            i++;
        }
    }
    fclose(f);
    return i;
}

char** insertParole(char *nomeFile){
    FILE* f;
    char **schema;
    char buffer[30];
    int i=0;
    schema=(char**)malloc(sizeof(char*)*trovaLunghezza(nomeFile));
    f = fopen(nomeFile,"r");
    while (!feof(f)){
        int m= fscanf(f,"%s",buffer);
        if(m>0){
            schema[i]=miastrdup(buffer);
            i++;
        }
    }
    fclose(f);
    return schema;
}

/* stampa un vettore di stringhe */
void stampaV(char **parole, int numeroParole)
{
    int i = 0;
    for (i=0; i<numeroParole; i++)
    {
        printf("%s", parole[i]);
        if (i<numeroParole-1) {
            printf(" ");
        }
    }
    printf("\n");
}

int verificaCoppia(char *s1, char *s2)
{
    int i, differenze = 0;
    int temp;
    int v1[256];
    int v2[256];

    for (i=0; i<256; i++)
    {
        v1[i] = 0;
        v2[i] = 0;
    }

    for (i=0; i<strlen(s1); i++)
    {
        temp = (int)s1[i];
        v1[temp]++;
    }
    for (i=0; i<strlen(s2); i++)
    {
        temp = (int)s2[i];
        v2[temp]++;

    }
    for (i=0; i<256; i++)
    {
        if (v1[i] != v2[i])
            differenze++;
    }
    switch (differenze)
    {
        case 0:
            return 1;
            break;
        case 1:
            return 1;
            break;
        case 2:
            return 1;
            break;
        default:
            return 0;
    }
}

/* verifica che un vettore di puntatori sia "vuoto" */
int emptyV(char **vett, int dim)
{
    int i=0;
    for (i=0; i<dim; i++)
    {
        if (vett[i] != NULL)
            return 0;
    }
    return 1;
}

int risolvi_labirinto(char **pool, char **catena, int dim)
{
    int i = 0, j;
    char *temp = NULL;



    if (emptyV(pool, dim))
    {
        return 1;
    }

    while (catena[i] != NULL && i+1 != dim)
        i++;



    for (j=1; j<dim; j++)
    {
        if ((pool[j] != NULL) && verificaCoppia(toLower(catena[i-1]),toLower(pool[j])) == 1)
        {
            catena[i] = pool[j];
            temp = miastrdup(pool[j]);
            pool[j] = NULL;
            if (risolvi_labirinto(pool, catena, dim) == 1)
                return 1;
            pool[j] = temp;
            catena[i] = NULL;
        }
    }
    return 0;
}


char** risoluzione(char* nomeFile){

    int dim = trovaLunghezza(nomeFile);
    char **pool = insertParole(nomeFile);
    char **catena = malloc(sizeof(char*)*dim);
    int i=0;

    while(i<dim){
        catena[i]=NULL;
        i++;
    }

    catena[0]=pool[0];
    pool[0]=NULL;

    risolvi_labirinto(pool, catena, dim);
    stampaV(catena, dim);
    return catena;
}

int main()
{
    char file[50];

    scanf("%s",file);
    risoluzione(file);

    return 0;
}
