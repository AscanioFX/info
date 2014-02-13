#include <stdio.h>
#include <unistd.h>
#define ORDINE 5
#define DIM (ORDINE*ORDINE)

// (condizione ? se_vero : se_falso)

int giusta(int m[DIM][DIM], int n, int cr)
{
    int cifre[DIM];
    int i;
    for(i=0;i<DIM;i++)
        cifre[i]=0;

    for(i=0;i<DIM;i++)
        if(m[cr==0?i:n][cr==0?n:i]>0)
            if(cifre[m[cr==0?i:n][cr==0?n:i]-1]>0)
                return 0;
            else
                cifre[m[cr==0?i:n][cr==0?n:i]-1]++;

    return 1;
}

int colonna_giusta(int m[DIM][DIM], int c)
{
    return giusta(m,c,0);
}

int riga_giusta(int m[DIM][DIM], int r)
{
    return giusta(m,r,1);
}

int cella_quadro_x(int x, int y, int n) // ritorna la riga dell'n-simo elemento del quadro x,y
{
    return x*ORDINE+n/ORDINE;
}
int cella_quadro_y(int x, int y, int n)
{
    return y*ORDINE+n%ORDINE;
}


int quadro_giusto(int m[DIM][DIM], int x, int y)
{
    int cifre[DIM];
    int i;
    for (i=0;i<DIM;i++)
        cifre[i]=0;

    for(i=0;i<DIM;i++)
        if(m[cella_quadro_x(x,y,i)][cella_quadro_y(x,y,i)]>0)
        {
            if(cifre[m[cella_quadro_x(x,y,i)][cella_quadro_y(x,y,i)]-1]>0)
                return 0;
            else
            {
                cifre[m[cella_quadro_x(x,y,i)][cella_quadro_y(x,y,i)]-1]++;
            }
        }
    return 1;
}

int schema_giusto(int m[DIM][DIM])
{
    int i;
    for(i=0;i<DIM;i++)
    {
        if(riga_giusta(m,i)==0)
            return 0;
        if(colonna_giusta(m,i)==0)
            return 0;
        if(quadro_giusto(m,i/ORDINE,i%ORDINE)==0)
            return 0;
    }
    return 1;
}

void stampa_sudoku(int m[DIM][DIM])
{
    int i,j;
    for (i=0;i<DIM;i++)
    {
        for(j=0;j<DIM;j++)
        {
            printf("%i ",m[i][j]);
            if(m[i][j]<10) printf(" ");
            if((j+1)%ORDINE==0) printf("  ");
        }
        printf("\n");
        if((i+1)%ORDINE==0) printf("\n");
    }
}


int risolvi_sudoku(int m[DIM][DIM])
{
    int i,j,k;
    if(schema_giusto(m)==0)
        return 0;

    for(i=0;i<DIM;i++)
        for(j=0;j<DIM;j++)
            if(m[i][j]==0)
            {
                for(k=1;k<=DIM;k++)
                {
                    m[i][j]=k;
                    if(risolvi_sudoku(m)==1)
                        return 1;
                }
                m[i][j]=0;
                return 0;
            }
    return 1;
}

int svuota_sudoku(int s[DIM][DIM])
{
    int i,j;
    for(i=0;i<DIM;i++)
        for(j=0;j<DIM;j++)
            s[i][j]=0;
}

int main()
{
    int s[DIM][DIM];

    svuota_sudoku(s);
    risolvi_sudoku(s);
    stampa_sudoku(s);

}
