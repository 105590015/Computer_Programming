#include<stdio.h>
#include<ctype.h>
main()
{
    int s=0,g=1,i=10,j=0,k,l,p=0,t,n;
    double b=0.1,x=0.0;
    char c;
    scanf("%c",&c);
    while(c!='\n')
    {
        if((s==0)&&(c=='-'))
        {
            g=-1;
            s=1;
        }
        else if((s==0)&&(isdigit(c)))
        {
            s=5;
            x=(c-'0');
        }
        else if((s==1)&&(isdigit(c))&&(c!='0'))
        {
            x=g*(c-'0');
            s=2;
        }
        else if((s==2)&&(isdigit(c)))
        {
            x=x*i+g*(c-'0');
            s=2;
        }
        else if((s==2)&&(c=='.'))
        {
            s=3;
        }
        else if((s==3)&&(isdigit(c)))
        {
            s=4;
            x=x+(c-'0')*b*g;
            b=b/10;
            j=j+1;
        }
        else if((s==4)&&(isdigit(c))&&(j<=3))
        {
            s=4;
            x=x+(c-'0')*b*g;
            b=b/10;
            j=j+1;
        }
        else if((s==5)&&(isdigit(c)))
        {
            s=5;
            x=x*i+(c-'0');
        }
        else if((s==5)&&(c=='.'))
        {
            s=3;
        }
        else
        {
            x=8787;
            s=7;
        }
        scanf("%c",&c);
    }



    t=x;
    n=x*1000-0.5;
    if(g==1)
    {
        if(t!=x)
        {
            x=floor(x);
        }
        else if((x==0)||(x==1))
        {
            x=1000;
        }
        else if((x<=2)||(x>=1000))
        {
            x=8787;
        }
    }
    else if(g==-1)
    {
        if(t!=x)
        {
            if(n%100==0)
            {
                x=fabs((n%1000)/100);
            }
            else if(n%10==0)
            {
                x=fabs((n%1000)/10);
            }
            else
            {
                x=fabs(n%1000);
            }
        }
        else if((x>=-1000)&&(x<=-1))
        {
            x=x*(-11);
        }
        else if((x<=-1000)||(x>=-1))
        {
            x=8787;
        }
    }



    if(x==8787)
    {
        printf("error");
    }
    else
    {
        for(k=x;k>=2;k--)
        {
            for(l=k;l>0;l--)
            {
                if(k%l==0)
                {
                    p++;
                }
            }
            if(p==2)
            {
                printf("%d",k);
                break;
            }
            p=0;
        }
    }
}
