#include<stdio.h>
#include<math.h>
void f1(int x1,int y1,int x2,int y2,double *m,double *b)
{
    if(x1-x2==0)
    {
        *m=87;
        *b=87;
    }
    else
    {
        *m=(double)(y1-y2)/(x1-x2);
        *b=(double)(x2*y1-x1*y2)/(x2-x1);
    }
}

void f2(int x1, int y1, int x2, int y2, int *m1, int *m2, int *b1, int *b2)
{
    if(x1-x2==0)
    {
        *m1=x1;
        *m2=x1;
        *b1=x1;
        *b2=x1;
    }
    else
    {
        *m1=(y1-y2);
        *m2=(x1-x2);
        *b1=(x2*y1-x1*y2);
        *b2=(x2-x1);
    }
}

int main()
{
    int x1,x2,y1,y2,i,j,min1,min2;
    double m,b;
    int m1,m2,b1,b2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    f1(x1,y1,x2,y2,&m,&b);
    f2(x1,y1,x2,y2,&m1,&m2,&b1,&b2);
    if((m==87)&&(b==87))
    {
        printf("x=%d\n",x1);
    }
    else if(m==0)
    {
        if(b-(int)b==0)
        {
            printf("y=%.0lf\n",b);
        }
        else
        {
            if((int)(b*100)%10==0)
            {
                printf("y=%.1lf\n",b);
            }
            else
            {
                printf("y=%.2lf\n",b);
            }
        }
    }
    else
    {
        if(m-(int)m==0)
        {
            if(b-(int)b==0)
            {
                if(b>=0)
                {
                    if(m==1)
                    {
                        if(b==0)
                        {
                            printf("y=x\n");
                        }
                        else
                        {
                            printf("y=x+%.0lf\n",m,b);
                        }
                    }
                    else
                    {
                        if(b==0)
                        {
                            printf("y=%.0lfx\n",m);
                        }
                        else
                        {
                            printf("y=%.0lfx+%.0lf\n",m,b);
                        }
                    }
                }
                else
                {
                    if(m==1)
                    {
                        printf("y=x-%.0lf\n",-b);
                    }
                    else
                    {
                        printf("y=%.0lfx-%.0lf\n",m,-b);
                    }
                }
            }
            else
            {
                if(b>0)
                {
                    if(m==1)
                    {
                        if((int)(b*100)%10==0)
                        {
                            printf("y=x+%.1lf\n",b);
                        }
                        else
                        {
                            printf("y=x+%.2lf\n",b);
                        }
                    }
                    else
                    {
                            if((int)(b*100)%10==0)
                            {
                                printf("y=%.0lfx+%.1lf\n",m,b);
                            }
                            else
                            {
                                printf("y=%.0lfx+%.2lf\n",m,b);
                            }
                    }
                }
                else
                {
                    if(m==1)
                    {
                        if((int)(b*100)%10==0)
                        {
                            printf("y=x-%.1lf\n",-b);
                        }
                        else
                        {
                            printf("y=x-%.2lf\n",-b);
                        }
                    }
                    else
                    {
                            if((int)(b*100)%10==0)
                            {
                                printf("y=%.0lfx-%.1lf\n",m,-b);
                            }
                            else
                            {
                                printf("y=%.0lfx-%.2lf\n",m,-b);
                            }
                    }
                }
            }
        }
        else
        {
            if(b-(int)b==0)
            {
                if(b>=0)
                {
                    if((int)(m*100)%10==0)
                    {
                        if(b==0)
                        {
                            printf("y=%.1lfx\n",m);
                        }
                        else
                        {
                            printf("y=%.1lfx+%.0lf\n",m,b);
                        }
                    }
                    else
                    {
                        if(b==0)
                        {
                            printf("y=%.2lfx\n",m);
                        }
                        else
                        {
                            printf("y=%.2lfx+%.0lf\n",m,b);
                        }
                    }
                }
                else
                {
                    if((int)(m*100)%10==0)
                    {
                        printf("y=%.1lfx-%.0lf\n",m,-b);
                    }
                    else
                    {
                        printf("y=%.2lfx-%.0lf\n",m,-b);
                    }
                }
            }
            else
            {
                if(b>0)
                {
                    if((int)(m*100)%10==0)
                    {
                        if((int)(b*100)%10==0)
                        {
                            printf("y=%.1lfx+%.1lf\n",m,b);
                        }
                        else
                        {
                            printf("y=%.1lfx+%.2lf\n",m,b);
                        }
                    }
                    else
                    {
                        if((int)(b*100)%10==0)
                        {
                            printf("y=%.2lfx+%.1lf\n",m,b);
                        }
                        else
                        {
                            printf("y=%.2lfx+%.2lf\n",m,b);
                        }
                    }
                }
                else
                {
                    if((int)(m*100)%10==0)
                    {
                        if((int)(b*100)%10==0)
                        {
                            printf("y=%.1lfx-%.1lf\n",m,-b);
                        }
                        else
                        {
                            printf("y=%.1lfx-%.2lf\n",m,-b);
                        }
                    }
                    else
                    {
                        if((int)(b*100)%10==0)
                        {
                            printf("y=%.2lfx-%.1lf\n",m,-b);
                        }
                        else
                        {
                            printf("y=%.2lfx-%.2lf\n",m,-b);
                        }
                    }
                }
            }
        }
    }

    if((m1==x1)&&(m2==x1)&&(b1==x1)&&(b2==x1))
    {
        printf("x=%d",x1);
    }
    else if((double)m1/m2==0)
    {
        if(m1>m2) {min1=m2;}
        else      {min1=m1;}
        if(b1>b2) {min2=b2;}
        else      {min2=b1;}
        for(i=abs(min1);i>=2;i--)
        {
            if((m1%i==0)&&(m2%i==0))
            {
                m1=m1/i;
                m2=m2/i;
            }
        }
        for(j=abs(min2);j>=2;j--)
        {
            if((b1%j==0)&&(b2%j==0))
            {
                b1=b1/j;
                b2=b2/j;
            }
        }
        if((double)b1/b2-b1/b2==0)
        {
            printf("y=%d",b1/b2);
        }
        else
        {
            if(((b1>0)&&(b2<0))||((b1<0)&&(b2<0)))
            {
                b1*=-1;
                b2*=-1;
            }
            printf("y=%d/%d",b1,b2);
        }
    }
    else
    {
        if(m1>m2) {min1=m2;}
        else      {min1=m1;}
        if(b1>b2) {min2=b2;}
        else      {min2=b1;}
        for(i=abs(min1);i>=2;i--)
        {
            if((m1%i==0)&&(m2%i==0))
            {
                m1=m1/i;
                m2=m2/i;
            }
        }
        for(j=abs(min2);j>=2;j--)
        {
            if((b1%j==0)&&(b2%j==0))
            {
                b1=b1/j;
                b2=b2/j;
            }
        }
        if((double)m1/m2-m1/m2==0)
        {
            if((double)b1/b2-b1/b2==0)
            {
                if(b1/b2>=0)
                {
                    if(m1/m2==1)
                    {
                        if(b1/b2==0)
                        {
                            printf("y=x");
                        }
                        else
                        {
                            printf("y=x+%d",b1/b2);
                        }
                    }
                    else
                    {
                        if(b1/b2==0)
                        {
                            printf("y=%dx",m1/m2);
                        }
                        else
                        {
                            printf("y=%dx+%d",m1/m2,b1/b2);
                        }
                    }
                }
                else
                {
                    if(m1/m2==1)
                    {
                        printf("y=x-%d",-(b1/b2));
                    }
                    else
                    {
                        printf("y=%dx-%d",m1/m2,-(b1/b2));
                    }
                }
            }
            else
            {
                if(((b1>0)&&(b2<0))||((b1<0)&&(b2<0)))
                {
                    b1=b1*-1;
                    b2=b2*-1;
                }
                if(b1/b2>=0)
                {
                    if(m1/m2==1)
                    {
                        printf("y=x+%d/%d",b1,b2);
                    }
                    else
                    {
                        printf("y=%dx+%d/%d",m1/m2,b1,b2);
                    }
                }
                else
                {
                    if(m1/m2==1)
                    {
                        printf("y=x-%d/%d",-b1,b2);
                    }
                    else
                    {
                        printf("y=%dx-%d/%d",m1/m2,-b1,b2);
                    }
                }
            }
        }
        else
        {
            if((double)b1/b2-b1/b2==0)
            {
                if(((m1<0)&&(m2<0))||((m1>0)&&(m2<0)))
                {
                    m1=m1*-1;
                    m2=m2*-1;
                }
                if(b1/b2>=0)
                {
                    if(b1/b2==0)
                    {
                        printf("y=%d/%dx",m1,m2);
                    }
                    else
                    {
                        printf("y=%d/%dx+%d",m1,m2,b1/b2);
                    }
                }
                else
                {
                    if(b1/b2==0)
                    {
                        printf("y=%d/%dx",m1,m2);
                    }
                    else
                    {
                        printf("y=%d/%dx-%d",m1,m2,-(b1/b2));
                    }
                }
            }
            else
            {
                if(((m1<0)&&(m2<0))||((m1>0)&&(m2<0)))
                {
                    m1=m1*-1;
                    m2=m2*-1;
                }
                if(((b1>0)&&(b2<0))||((b1<0)&&(b2<0)))
                {
                    b1=b1*-1;
                    b2=b2*-1;
                }
                if(b1/b2>=0)
                {
                    printf("y=%d/%dx+%d/%d",m1,m2,b1,b2);
                }
                else
                {
                    printf("y=%d/%dx-%d/%d",m1,m2,-b1,b2);
                }
            }
        }
    }
}
