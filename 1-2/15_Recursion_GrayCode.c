#include<stdio.h>
int pow(int x,int y)
{
    int i,sum=1;
    for(i=0;i<y;i++)
        sum*=x;
    return sum;
}
int GrayCode(int n,int k)
{
    if(n==1)
        printf("%d",k);
    else if(k<pow(2,(n-1)))
    {
        printf("0");
        return GrayCode(n-1,k);
    }
    else if(k>=pow(2,(n-1)))
    {
        printf("1");
        return GrayCode(n-1,pow(2,n)-1-k);
    }
}
main()
{
    int n,k,judge=0;
    while(judge!=-1)
    {
        scanf("%d %d",&n,&k);
        GrayCode(n,k);
        printf("\n");
        scanf("%d",&judge);
    }
}
