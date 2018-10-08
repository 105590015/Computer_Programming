#include <stdio.h>
main()
{
    int a,b;
    void PrintRight(int x);
    void PrintLeft(int y);
    scanf("%d%d",&a,&b);
    if(a==1)
    {
        PrintRight(b);
    }
    else
    {
        PrintLeft(b);
    }
}

void PrintRight(int x)
{
    int i,j,k,l;
    for(i=1;i<=x/2+1;i++)
    {
        for(j=1;j<=x/2+1;j++)
        {
            if(i>=j)
            {
                printf("%d",j);
            }
        }
        printf("\n");
    }
    for(k=x/2;k>=1;k--)
    {
        for(l=1;l<=x/2;l++)
        {
            if(k>=l)
            {
                printf("%d",l);
            }
        }
        printf("\n");
    }
}

void PrintLeft(int y)
{
    int i,j,k,l;
    for(i=1;i<=y/2+1;i++)
    {
        for(j=y/2+1;j>=1;j--)
        {
            if(i>=j)
            {
                printf("%d",j);
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
    for(k=y/2;k>=1;k--)
    {
        for(l=y/2+1;l>=1;l--)
        {
            if(k>=l)
            {
                printf("%d",l);
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
}
