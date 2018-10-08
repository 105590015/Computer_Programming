#include<stdio.h>
#include<math.h>
main()
{
    int f,err,jud;
    double t1=0.0,t2=0.0,h=0.0,n=2.0,a=0.0,p=0.0,q=0.0;
    double f1(double a,double x);
    double f2(double a,double x);
    double f1a(double a,double p,double h,double n);
    double f2a(double a,double p,double h,double n);
    scanf("%d,%lf,%lf,%lf,%d,%d",&f,&a,&p,&q,&err,&jud);
    h=(q-p)/n;
    if(f==1)
    {
        t2=(h/2.0)*(f1(a,p)+f1(a,q)+f1a(a,p,h,n));
        while(fabs(t2-t1)*pow(10,err)>1)
        {
            t1=t2;
            n=n+1.0;
            h=(q-p)/n;
            t2=(h/2.0)*(f1(a,p)+f1(a,q)+f1a(a,p,h,n));
        }
        printf("%.5lf",floor(t2*100000+0.5)/100000);
    }
    if(f==2)
    {
        t2=(h/2.0)*(f2(a,p)+f2(a,q)+f2a(a,p,h,n));
        while(fabs(t2-t1)*pow(10,err)>1)
        {
            t1=t2;
            n=n+1.0;
            h=fabs((q-p)/n);
            t2=(h/2.0)*(f2(a,p)+f2(a,q)+f2a(a,p,h,n));
        }
        printf("%.5lf",floor(t2*100000+0.5)/100000);
    }
}

double f1(double a,double x)
{
    double b;
    b=pow(x,2);
    return sqrt(a-b);
}

double f1a(double a,double p,double h,double n)
{
    int i;
    double sum=0.0;
    for(i=1;i<n;i++)
    {
        sum=sum+f1(a,(double)p+h*i);
    }
    return 2.0*sum;
}

double f2(double a,double x)
{
    double b,c;
    b=fabs(a*pow(x,3)+7*x);
    c=sqrt(a+x);
    return fabs(b/c);
}

double f2a(double a,double p,double h,double n)
{
    int i;
    double sum=0.0;
    for(i=1;i<n;i++)
    {
        sum=fabs(sum+f2(a,(double)p+h*i));
    }
    return 2.0*sum;
}



