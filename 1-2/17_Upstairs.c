#include<stdio.h>
main()
{
    int i,n;
    unsigned long long int x[70]={0};
    scanf("%d",&n);
    x[0]=0;
    x[1]=1;
    x[2]=2;
    x[3]=4;
    for(i=4;i<70;i++)
        x[i]=x[i-1]+x[i-2]+x[i-3];
    printf("%lld",x[n]);
}
