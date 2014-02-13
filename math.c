#include <stdio.h>

/* ritorna 1 se il numero è primo, altrimenti 0 */
int primo(int n)
{
    int i;
    for (i=2; i<n; i++)
    {
        if (n%i == 0)
            return 0;
    }
    return 1;
}

/* ritorna il numero primo successivo */
int nextPrimo(int n)
{
    int i = n+1;
    while(1)
    {
        if (primo(i))
            return i;
        i++;
    }
}

/* ritorna il massimo comune divisore */
int maxComune(int a, int b)
{
    int max = 1;
    int i, j;

    for (i=1; i<=a; i++)
    {
        if (a%i == 0)
            for (j=1; j<=b; j++)
            {
                if (b%j == 0 && j == i && i > max)
                    max = i;
            }
    }
    return max;
}

/* ritorna 1 se i due numeri hanno un solo divisore in comune, altrimenti 0 */
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

/* eleva a alla b */
int potenza(int a, int b)
{
    int potenza = 1;
    int i;
    if (b == 0)
        return 1;
    for (i=0; i<b; i++)
        potenza = potenza * a;
    return potenza;
}
