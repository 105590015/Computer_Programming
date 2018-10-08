#include<stdio.h>
int judge(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
    int s1,s2,m;
    /*printf("%d,%d,%d,%d,%d,%d,%d,%d\n",x1,y1,x2,y2,x3,y3,x4,y4);*/
    m=(y4-y3)*(x2-x1)-(x4-x3)*(y2-y1);
    s1=(x4-x3)*(y1-y3)-(y4-y3)*(x1-x3);
    s2=(x2-x1)*(y1-y3)-(y2-y1)*(x1-x3);
    if(m<0)
    {
        s1*=-1;
        s2*=-1;
        m*=-1;
    }
    /*printf("%d,%d,%d\n",m,s1,s2);*/
    return (0<=s1)&&(s1<=m)&&(m!=0)&&(0<=s2)&&(s2<=m);
}
int f(int x[],int y[],int n1,int n2,double xfocus[],double yfocus[],int *ma)
{
    int j,k,s=0,t,u;
    double m1,m2,b1,b2,xf=0.0,yf=0.0,xo=0.0,yo=0.0;
    for(j=3*n1;j<3*n1+3;j++)
    {
        u=j+1;
        if(u==3*n1+3)
            u-=3;
        for(k=3*n2;k<3*n2+3;k++)
        {
            t=k+1;
            if(t==3*n2+3)
                t-=3;
            if(judge(x[j],y[j],x[u],y[u],x[k],y[k],x[t],y[t])==1)
            {
                if(x[u]-x[j]!=0&&x[t]-x[k]!=0)
                {
                    m1=(double)(y[u]-y[j])/(x[u]-x[j]);
                    m2=(double)(y[t]-y[k])/(x[t]-x[k]);
                    b1=(double)(x[u]*y[j]-x[j]*y[u])/(x[u]-x[j]);
                    b2=(double)(x[t]*y[k]-x[k]*y[t])/(x[t]-x[k]);
                    xf=(b2-b1)/(m1-m2);
                    yf=m1*xf+b1;
                }
                else if(x[u]-x[j]==0)
                {
                    xf=x[u];
                    m2=(double)(y[t]-y[k])/(x[t]-x[k]);
                    b2=(double)(x[t]*y[k]-x[k]*y[t])/(x[t]-x[k]);
                    yf=m2*xf+b2;
                }
                else if(x[t]-x[k]==0)
                {
                    xf=x[t];
                    m1=(double)(y[u]-y[j])/(x[u]-x[j]);
                    b1=(double)(x[u]*y[j]-x[j]*y[u])/(x[u]-x[j]);
                    yf=m1*xf+b1;
                }
                if(xf!=xo||yf!=yo)
                {
                    xfocus[*ma]=xf;
                    yfocus[*ma]=yf;
                    *ma+=1;
                    s++;
                    xo=xf;
                    yo=yf;
                    /*printf("%.1f,%.1f\n",xf,yf);*/
                }
            }
        }
    }
    /*printf("%d\n",s);*/
    if(s==0)
        return 0;
    else
        return 1;
}
main()
{
    int n,i=0,j,k,sum=1,l,p,ma=0,num=0,b1,b2,o,fa=10,fa2=10;
    int x[50]={0},y[50]={0};
    double xfocus[50]={0},yfocus[50]={0},t1,t2;
    scanf("%d",&n);
    while(i<(n*3))
    {
        scanf("%d %d",&x[i],&y[i]);
        scanf("%d %d",&x[i+1],&y[i+1]);
        scanf("%d %d",&x[i+2],&y[i+2]);
        i+=3;
    }
    for(j=0;j<n;j++)
    {
        for(k=j+1;k<n;k++)
        {
            if(f(x,y,j,k,xfocus,yfocus,&ma)==1)
                sum++;
        }
    }
    for(l=0;l<ma;l++)
    {
        for(p=l+1;p<ma;p++)
        {
            if(xfocus[l]==xfocus[p]&&yfocus[l]==yfocus[p])
            {
                xfocus[p]=0;
                yfocus[p]=0;
            }
        }
    }
    for(b1=0;b1<ma;b1++)
    {
        for(b2=b1;b2<ma;b2++)
        {
            if(xfocus[b1]>xfocus[b2])
            {
                t1=xfocus[b1];
                t2=yfocus[b1];
                xfocus[b1]=xfocus[b2];
                yfocus[b1]=yfocus[b2];
                xfocus[b2]=t1;
                yfocus[b2]=t2;
            }
            else if(xfocus[b1]==xfocus[b2])
            {
                if(yfocus[b1]>yfocus[b2])
                {
                    t1=xfocus[b1];
                    t2=yfocus[b1];
                    xfocus[b1]=xfocus[b2];
                    yfocus[b1]=yfocus[b2];
                    xfocus[b2]=t1;
                    yfocus[b2]=t2;
                }
            }
        }
    }
    for(l=0;l<50;l++)
    {
        if(xfocus[l]!=0||yfocus[l]!=0)
            num++;
    }
    /*for(l=0;l<50;l++)
        printf("%.1f,%.1f\n",xfocus[l],yfocus[l]);*/
    for(l=ma-num;l<ma;l++)
    {
        if(xfocus[l]-(int)xfocus[l]==0&&yfocus[l]-(int)yfocus[l]==0)
            printf("(%.0f,%.0f)\n",xfocus[l],yfocus[l]);
        else if(xfocus[l]-(int)xfocus[l]!=0&&yfocus[l]-(int)yfocus[l]==0)
        {
            xfocus[l]*=10;
            for(o=10;o>1;o--)
            {
                if((int)xfocus[l]%o==0&&fa%o==0)
                {
                    xfocus[l]=xfocus[l]/o;
                    fa=fa/o;
                }
            }
            printf("(%.0f/%d,%.0f)\n",xfocus[l],fa,yfocus[l]);
            fa=10;
        }
        else if(xfocus[l]-(int)xfocus[l]==0&&yfocus[l]-(int)yfocus[l]!=0)
        {
            yfocus[l]*=10;
            for(o=10;o>1;o--)
            {
                if((int)yfocus[l]%o==0&&fa%o==0)
                {
                    yfocus[l]=yfocus[l]/o;
                    fa=fa/o;
                }
            }
            printf("(%.0f,%.0f/%d)\n",xfocus[l],yfocus[l],fa);
            fa=10;
        }
        else if(xfocus[l]-(int)xfocus[l]!=0&&yfocus[l]-(int)yfocus[l]!=0)
        {
            xfocus[l]*=10;
            yfocus[l]*=10;
            for(o=10;o>1;o--)
            {
                if((int)xfocus[l]%o==0&&fa%o==0)
                {
                    xfocus[l]=xfocus[l]/o;
                    fa=fa/o;
                }
            }
            for(o=10;o>1;o--)
            {
                if((int)yfocus[l]%o==0&&fa2%o==0)
                {
                    yfocus[l]=yfocus[l]/o;
                    fa2=fa2/o;
                }
            }
            printf("(%.0f/%d,%.0f/%d)\n",xfocus[l],fa,yfocus[l],fa2);
            fa=10;
            fa2=10;
        }

    }
    /*printf("%d",num);*/
   /* if(sum==1)
        printf("0");
    else
        printf("%d%\n",sum);*/
}
