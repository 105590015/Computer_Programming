#include <stdio.h>
int priority(char c)
{
    if(c=='^')               return 3;
    else if(c=='*'||c=='/')  return 2;
    else if(c=='+'||c=='-')  return 1;
    else                     return 0;
}
void inToPostfix(char infix[],char postfix[])
{
    char stack[100];
    int i,j=0,top=0;
    while(infix[i]!='\0')
    {
        if(infix[i]=='(')
            stack[++top]=infix[i];
        else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^')
        {
            while(priority(stack[top])>=priority(infix[i]))
                postfix[j++]=stack[top--];
            stack[++top]=infix[i];
        }
        else if(infix[i]==')')
        {
            while(stack[top]!='(')
                postfix[j++]=stack[top--];
            top--;
        }
        else
        {
            postfix[j++]=infix[i];
        }
        i++;
    }
    while(top>0)
        postfix[j++]=stack[top--];
}
main()
{
    int i;
    char infix[512]={'\0'},postfix[512]={'\0'};
    scanf("%s",infix);
    inToPostfix(infix,postfix);
    for(i=0;postfix[i]!='\0';i++)
        printf("%c",postfix[i]);
}
