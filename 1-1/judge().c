#include<stdio.h>
main()
{
    int i=0,j,a=0,b=0,index=10,o1=0,o2=0,sum=0,v=0,t1[50]={0},t2[50]={0},com[50]={0};
    char str[100]={0},sign[50]={0};
    scanf("%c",&str[0]);
    while(str[i]!='\n')
    {
        i++;
        scanf("%c",&str[i]);
    }
    for(j=0;j<100;j++)
    {
        if(str[j]=='(')
            {a++; t1[a]=j;}
        if(str[j]==')')
            {b++; t2[b]=j;}
    }
    if(a!=b)
        printf("ERROR INPUT");
    else
    {
        for(j=t1[a]+1;j<t2[1];j++)
        {
            printf("%c",str[j]);
            if(isdigit(str[j]))
                {com[o1]=com[o1]*index+str[j]-48;}
            else
                {o1++; sign[o2]=str[j]; o2++;}
        }
        printf("\n");
        if(str[t1[a]+1]=='-')
        {
            for(j=0;j<49;j++)
                {com[j]=com[j+1]; sign[j]=sign[j+1];}
            com[0]*=-1;
        }
        for(j=0;j<49;j++)
        {
            if(sign[j]=='*')
            {
                com[j]*=com[j+1];
                com[j+1]=com[j];
            }
        }
        for(j=0;j<49;j++)
        {
            if(sign[j]=='+')
            {
                sum+=com[j]+com[j+1];
                com[j+1]=0;
            }
            if(sign[j]=='-')
            {
                sum+=com[j]-com[j+1];
                com[j+1]=0;
            }
        }
        for(j=0;j<20;j++)
        {
            if(sign[j]=='+'||sign[j]=='-')
                v++;
        }
        if(v==0)
        {
            for(j=19;j>=0;j--)
                if(com[j]!=0)
                {
                    printf("%d",com[j]);
                    break;
                }
        }
        else
            printf("%d",sum);
    }
}
