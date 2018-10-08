#include <stdio.h>
main()
{
    void print(int x,char y);
    int a,i;
    scanf("%d",&a);
    for(i=1;i<=a/2+1;i++)
    {
        print(a/2+1-i,'.');
        print(i*2-1,'*');
        print(a/2+1-i,'.');
        printf("\n");
    }
    for(i=a/2;i>=1;i--)
    {
        print(a/2+1-i,'.');
        print(i*2-1,'*');
        print(a/2+1-i,'.');
        printf("\n");
    }
}

void print(int x,char y)
{
    int i;
    for(i=1;i<=x;i++)
    {
        printf("%c",y);
    }
}
