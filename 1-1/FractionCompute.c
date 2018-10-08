#include<stdio.h>
void add(int n1, int d1, int n2, int d2, int *numerator, int *denominator)
{
    if(d1==d2)
    {
        *numerator=n1+n2;
        *denominator=d1;

    }
    else
    {
        *numerator=n1*d2+n2*d1;
        *denominator=d1*d2;
    }
}

int multiply(int n1, int d1, int n2, int d2, int *numerator, int *denominator)
{
    *numerator=n1*n2;
    *denominator=d1*d2;
}

main()
{
    int n1,d1,n2,d2,min1,min2,i,j,z1,z2;
    int num1,num2,den1,den2;
    scanf("%d/%d %d/%d",&n1,&d1,&n2,&d2);
    add(n1,d1,n2,d2,&num1,&den1);
    multiply(n1,d1,n2,d2,&num2,&den2);
    if(abs(num1)>abs(den1))  {min1=abs(den1);}
    else                     {min1=abs(num1);}
    if(abs(num2)>abs(den2))  {min2=abs(den2);}
    else                     {min2=abs(num2);}
    for(i=min1;i>=2;i--)
    {
        if((num1%i==0)&&(den1%i==0))
        {
            num1=num1/i;
            den1=den1/i;
        }
    }
    for(j=min2;j>=2;j--)
    {
        if((num2%j==0)&&(den2%j==0))
        {
            num2=num2/j;
            den2=den2/j;
        }
    }
    if((n1==0)||(d1==0)||(n2==0)||(d2==0))
    {
        printf("ERROR\nERROR");
    }
    else if(abs(num1/den1)>=1)
    {
        if(abs(num2/den2)>=1)
        {
            z1=abs(num1/den1);
            z2=abs(num2/den2);
            if(num1<0)  {z1*=-1;  num1*=-1;}
            if(num2<0)  {z2*=-1;  num2*=-1;}
            if(den1<0)  {z1*=-1;  den1*=-1;}
            if(den2<0)  {z2*=-1;  den2*=-1;}
            if(z1>0)    {num1-=z1*den1;}
            else        {num1-=-1*z1*den1;}
            if(z2>0)    {num2-=z2*den2;}
            else        {num2-=-1*z2*den2;}
            if(num1==0)
            {
                if(num2==0)
                {
                    printf("%d\n",z1);
                    printf("%d",z2);
                }
                else
                {
                    printf("%d\n",z1);
                    printf("%d(%d/%d)",z2,num2,den2);
                }
            }
            else
            {
                if(num2==0)
                {
                    printf("%d(%d/%d)\n",z1,num1,den1);
                    printf("%d",z2);
                }
                else
                {
                    printf("%d(%d/%d)\n",z1,num1,den1);
                    printf("%d(%d/%d)",z2,num2,den2);
                }
            }

        }
        else
        {
            z1=abs(num1/den1);
            if(num1<0)  {z1*=-1;  num1*=-1;}
            if(den1<0)  {z1*=-1;  den1*=-1;}
            if(den2<0)  {num2*=-1;  den2*=-1;}
            if(z1>0)    {num1-=z1*den1;}
            else        {num1-=-1*z1*den1;}
            if(num1==0)
            {
                printf("%d\n",z1);
                printf("%d/%d",num2,den2);
            }
            else
            {
                printf("%d(%d/%d)\n",z1,num1,den1);
                printf("%d/%d",num2,den2);
            }
        }
    }
    else
    {
        if(abs(num2/den2)>=1)
        {
            z2=abs(num2/den2);
            if(num2<0)  {z2*=-1;  num2*=-1;}
            if(den1<0)  {num1*=-1;  den1*=-1;}
            if(den2<0)  {z2*=-1;  den2*=-1;}
            if(z2>0)    {num2-=z2*den2;}
            else        {num2-=-1*z2*den2;}
            if(num2==0)
            {
                printf("%d/%d\n",num1,den1);
                printf("%d",z2);
            }
            else
            {
                printf("%d/%d\n",num1,den1);
                printf("%d(%d/%d)",z2,num2,den2);
            }
        }
        else
        {
            if(den1<0)  {num1*=-1;  den1*=-1;}
            if(den2<0)  {num2*=-1;  den2*=-1;}
            printf("%d/%d\n",num1,den1);
            printf("%d/%d",num2,den2);
        }
    }
}
