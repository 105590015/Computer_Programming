#include<stdio.h>
#include<math.h>
main()
{
    int b,n,i=0;
    double x,a=0;
    scanf("%d%d",&b,&n);
    if((b<2)||(b>9)||(n<0)||(n>10000000))
    {
        printf("-1");
    }
    else
    {
        while(1)
        {
            x=n%b;
            n=n/b;
            a=a+x*(double)pow(10,i);
            i=i+1;
            if(n/b<1)
            {
                a=a+n*pow(10,i);
                break;
            }
        }
        printf("%.f",a);
    }
}
