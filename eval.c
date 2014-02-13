#include <stdio.h>

int toInt(char n)
{
    return n-48;
}
/* funziona come atoi */
int getNu(char* s)
{
    int i, n = 0;

    for (i=0; s[i] != '\0'; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return n;
        else
            n = n*10+toInt(s[i]);
    }
    return n;
}

/* ritorna il numero delle cifre del numero */
int numLen(int n)
{
    int i;
    for (i=0; n>0; i++)
        n = n/10;
    return i;
}

int eval(char* s)
{
    char op = '+';
    int i, buff;
    int tot = 0;

    for (i=0; s[i] != '\0'; i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            op = s[i];
        else
        {
            buff = getNu(s+i);
            switch(op)
            {
                case '+':
                    tot = tot + buff;
                    break;
                case '-':
                    tot = tot - buff;
                    break;
                case '*':
                    tot = tot * buff;
                    break;
                case '/':
                    tot = tot / buff;
                default:
                    printf("ERRORE [eval] :: operatore non valido.\n");
            }
            i = i + numLen(buff) - 1;
        }
        /*sleep(1);*/
    }
    return tot;
}
