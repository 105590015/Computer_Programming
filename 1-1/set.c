#include<stdio.h>
void f1(int *A)
{
    int i;
    for(i=0;i<20;i++)
    {
        *(A+i)=0;
    }
}
void f2(int *A,int integer,int *i)
{
    int x,s=0;
    for(x=0;x<20;x++)
    {
        if(*(A+x)==integer)
            s++;
    }
    if(s==0)
    {
        *(A+*i)=integer;
        *i=*i+1;
    }
}
void f3(int *A,int integer)
{
    int x;
    for(x=0;x<20;x++)
    {
        if(*(A+x)==integer)
            *(A+x)=0;
    }
}
void f4(int *A,int *B)
{
    int i,j,k,s=0;
    printf("[");
    for(i=0;i<20;i++)
    {
        if(*(A+i)!=0)
        {
            printf("%d,",*(A+i));
        }
    }
    for(j=0;j<20;j++)
    {
        for(k=0;k<20;k++)
        {
            if(*(B+j)==*(A+k))
                s++;
        }
        if((s==0)&&(*(B+j)!=0))
        {
            printf("%d,",*(B+j));
        }
        s=0;
    }
    printf("]\n");
}
void f5(int *A,int *B)
{
    int i,j;
    printf("[");
    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
        {
            if((*(A+i)==*(B+j))&&(*(A+i)!=0))
                printf("%d,",*(A+i));
        }
    }
    printf("]\n");
}
void f6(int *A,int *B)
{
    int i,j,k,s=0,t=0;
    for(i=0;i<20;i++)
    {
        if(*(A+i)!=0)
            s++;
    }
    for(j=0;j<20;j++)
    {
        for(k=0;k<20;k++)
        {
            if((*(A+j)==*(B+k))&&(*(A+j)!=0))
                t++;
        }
    }
    if(t==s)
        printf("1\n");
    else
        printf("0\n");
}
void print(int *A,int *B)
{
    int t,y;
    printf("A:[");
    for(t=0;t<20;t++)
    {
        if(*(A+t)!=0)
            printf("%d,",*(A+t));
    }
    printf("]B:[");
    for(y=0;y<20;y++)
    {
        if(*(B+y)!=0)
            printf("%d,",*(B+y));
    }
    printf("]\n");
}
main()
{
    int A[20]={0};
    int B[20]={0};
    int jud,integer,i=0,j=0;
    scanf("%d",&jud);
    while(jud!=0)
    {
        if(jud==1)
        {
            f1(A);
            print(A,B);
        }
        else if(jud==2)
        {
            f1(B);
            print(A,B);
        }
        else if(jud==3)
        {
            scanf("%d",&integer);
            f2(A,integer,&i);
            print(A,B);
        }
        else if(jud==4)
        {
            scanf("%d",&integer);
            f2(B,integer,&j);
            print(A,B);
        }
        else if(jud==5)
        {
            scanf("%d",&integer);
            f3(A,integer);
            print(A,B);
        }
        else if(jud==6)
        {
            scanf("%d",&integer);
            f3(B,integer);
            print(A,B);
        }
        else if(jud==7)
            f4(A,B);
        else if(jud==8)
            f5(A,B);
        else if(jud==9)
            f6(A,B);
        scanf("%d",&jud);
    }
}
