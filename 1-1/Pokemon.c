#include<stdio.h>
main()
{
    double a,b,c;
    int ma=0,sum=0;
    scanf("%lf %lf %lf",&a,&b,&c);
    if((a<-100)||(a>0)||(b<0)||(b>30000)||(c<0)||(c>10000)||((int)(a*1000)%100!=0)||((int)(b*1000)%100!=0)||((int)(c*1000)%1000!=0))
    {
        printf("Error");
    }
    else
    {
        while((b>(-a))&&(c>0))
        {
            b=b+a+1.5;
            ma=ma+1;
            c=c-1.0;
            sum=sum+1;
            b=b+ma*1.5;
            ma=0;
            while(b<(-a)&&(c>=0.0))
            {
                c=c-1.0;
                b=b+1.5;
            }
        }
        printf("%d",sum);
    }
}
