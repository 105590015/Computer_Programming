#include<stdio.h>
void Percentage(int point,int a,int b)
{
    int ap,bp;
    char c='%';
    if(a==0&&b==0)
        printf("A:50%c,B:50%c\n",c,c);
    else if(a>0&&b<1)
        printf("A:100%c,B:0%c\n",c,c);
    else if(a<1&&b>0)
        printf("A:0%c,B:100%c\n",c,c);
    else
    {
        ap=a*100/(a+b);
        bp=100-ap;
        printf("A:%d%c,B:%d%c\n",ap,c,bp,c);
    }
}
void Deposit(int point,int money,int *a,int *b)
{
    if(point==0)
    {
        *a+=money;
        printf("A:Deposit,%d\nA:%d\n",money,*a);
    }
    else if(point==1)
    {
        *b+=money;
        printf("B:Deposit,%d\nB:%d\n",money,*b);
    }
}
void Withdraw(int point,int money,int *a,int *b)
{
    if(point==0)
    {
        *a-=money;
        printf("A:Withdraw,%d\nA:%d\n",money,*a);
    }
    else if(point==1)
    {
        *b-=money;
        printf("B:Withdraw,%d\nB:%d\n",money,*b);
    }
}
void Inquire(int point,int a,int b)
{
    if(point==0)
        printf("A:%d\n",a);
    else if(point==1)
        printf("B:%d\n",b);
}
main()
{
    int a=0,b=0,money,point;
    char instruction='\0';
    while(instruction!='e')
    {
        scanf("%c",&instruction);
        if(instruction=='a')
        {
            printf("Select A\n");
            point=0;
        }
        else if(instruction=='b')
        {
            printf("Select B\n");
            point=1;
        }
        else if(instruction=='v')
            Inquire(point,a,b);
        else if(instruction=='w')
        {
            scanf("%d",&money);
            Withdraw(point,money,&a,&b);
        }
        else if(instruction=='s')
        {
            scanf("%d",&money);
            Deposit(point,money,&a,&b);
        }
        else if(instruction=='p')
            Percentage(point,a,b);
    }
}
