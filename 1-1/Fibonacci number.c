#include<stdio.h>
main()
{
    double n;
    int i,j,t1=1,t2=1,sum=0;
    int jud(),u=0;
    while(1)
    {
        scanf("%lf",&n);
        j=n*1000;
        u=jud();
        if(n==-1)
        {
            break;
        }
        else if((n<1.0)||(j%1000!=0)||(u!=0))
        {
            printf("Error\n");
        }
        else if((n==1.0)||(n==2.0))
        {
            printf("1\n");
        }
        else
        {
            for(i=3;i<=(int)n;i++)
            {
                sum=t1+t2;
                t2=t1;
                t1=sum;
            }
            printf("%d\n",sum);
            t1=1;
            t2=1;
            sum=0;
        }
        u=0;
    }
}

int jud()
{
    int c,jud=0;
    while(1)
        {
            c=getchar();
            if(c=='\n')
            {
                break;
            }
            else if((c-48<0)||(c-48>9))
            {
                jud++;
            }
        }
        return jud;
}


