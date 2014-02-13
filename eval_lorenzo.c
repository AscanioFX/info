#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
int isANumber(char input)
{
    if(input>='0')
        if(input <= '9')
        	return 1;
    return 0;
}
int doExpression(int primo, int secondo, char oper)
{
    if(oper == '+')
        return primo+secondo;
    if(oper == '-')
        return primo-secondo;
    if(oper == '*')
        return primo*secondo;
    if(oper == '/')
        if(secondo !=0)
            return primo/secondo;
    return 0;
}
int IsOperand(char op)
{
    if(op=='+' || op == '-' || op=='/' || op=='*')
        return 1;
    return 0;
    
}
int eval(char* expr)
{
    int res=0, secondo = 0;
    char operatore = '+';
    int i;
    for(i=0; expr[i]!='\0'; i++)
    {
        if(IsOperand(expr[i]))
            operatore = expr[i];
        else
        {
            secondo = atoi(&expr[i]);
            
            while(isANumber ( expr[1+i]) )
                i++;
            res = doExpression(res, secondo, operatore);
            secondo = 0;
        }
        
    }
    
    
    return res;
}
