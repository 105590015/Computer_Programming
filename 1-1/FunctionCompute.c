#include<stdio.h>
void add(int *sumx,int *sumy)
{
    int i,j,k,l=0,o,temp1,temp2;
    for(i=0;i<20;i++)
    {
        for(j=i;j<20;j++)
        {
            if((*(sumy+j)>*(sumy+i))||((*(sumy+j)==*(sumy+i))&&(*(sumx+j)!=0)))
            {
                temp1=*(sumy+j);
                temp2=*(sumx+j);
                *(sumy+j)=*(sumy+i);
                *(sumx+j)=*(sumx+i);
                *(sumy+i)=temp1;
                *(sumx+i)=temp2;
            }
        }
    }
    for(k=0;k<19;k++)
    {
        if(*(sumy+k)==*(sumy+k+1))
        {
            *(sumx+k)=*(sumx+k)+*(sumx+k+1);
            *(sumx+k+1)=0;
        }
    }
    /*for(o=0;o<20;o++)
        printf("%d,%d\n",sumx[o],sumy[o]);*/
    if(*(sumx)<0)
        printf("-");
    while(sumx[l]!=0||sumy[l]!=0)
    {
        if(sumx[l+1]==0&&sumy[l+1]==0&&sumy[l]==1&&sumx[l]!=0)
            printf("%dx\n",abs(sumx[l]));
        else if(sumx[l+1]==0&&sumy[l+1]==0&&sumy[l]!=0&&sumx[l]!=0)
            printf("%dx^%d\n",abs(sumx[l]),sumy[l]);
        else if(sumx[l+1]==0&&sumy[l+1]==0&&sumy[l]==0&&sumx[l]!=0)
            printf("%d\n",abs(sumx[l]));
        else if(abs(sumx[l]==1)&&sumy[l]==1)
        {
            if(sumx[l+1]<0||(sumx[l+1]==0&&sumx[l+2]<0))
                printf("x - ");
            else
                printf("x + ");
        }
        else if(abs(sumx[l]==1)&&sumy[l]!=1)
        {
            if(sumx[l+1]<0||(sumx[l+1]==0&&sumx[l+2]<0))
                printf("x^%d - ",sumy[l]);
            else
                printf("x^%d + ",sumy[l]);
        }
        else if(abs(sumx[l])!=1&&sumy[l]==1&&sumx[l]!=0)
        {
            if(sumx[l+1]<0||(sumx[l+1]==0&&sumx[l+2]<0))
                printf("%dx - ",abs(sumx[l]));
            else
                printf("%dx + ",abs(sumx[l]));
        }
        else if(abs(sumx[l])!=1&&sumy[l]!=1&&sumx[l]!=0)
        {
            if(sumx[l+1]<0||(sumx[l+1]==0&&sumx[l+2]<0))
                printf("%dx^%d - ",abs(sumx[l]),sumy[l]);
            else
                printf("%dx^%d + ",abs(sumx[l]),sumy[l]);
        }
        l++;
    }
}
void subtraction(int *sumx,int *sumy)
{
    int i,j,k,t,l=0,o,m=0,temp1,temp2;
    for(k=0;k<10;k++)
    {
        for(t=10;t<20;t++)
        {
            if(*(sumy+k)==*(sumy+t))
            {
                *(sumx+k)=*(sumx+k)-*(sumx+t);
                *(sumx+t)=0;
            }
            if(*(sumy+k+10)==*(sumy+19-t))
                m++;
        }
        if(m==0)
            sumx[k+10]=-1*sumx[k+10];
        m=0;
    }
    for(i=0;i<20;i++)
    {
        for(j=i;j<20;j++)
        {
            if((*(sumy+j)>*(sumy+i))||((*(sumy+j)==*(sumy+i))&&(*(sumx+j)!=0)))
            {
                temp1=*(sumy+j);
                temp2=*(sumx+j);
                *(sumy+j)=*(sumy+i);
                *(sumx+j)=*(sumx+i);
                *(sumy+i)=temp1;
                *(sumx+i)=temp2;
            }
        }
    }
    if(*(sumx)<0)
        printf("-");
    while(sumx[l]!=0||sumy[l]!=0)
    {
        if(sumx[l+1]==0&&sumy[l+1]==0&&sumy[l]==1&&sumx[l]!=0)
            printf("%dx\n",abs(sumx[l]));
        else if(sumx[l+1]==0&&sumy[l+1]==0&&sumy[l]!=0&&sumx[l]!=0)
            printf("%dx^%d\n",abs(sumx[l]),sumy[l]);
        else if(sumx[l+1]==0&&sumy[l+1]==0&&sumy[l]==0&&sumx[l]!=0)
            printf("%d\n",abs(sumx[l]));
        else if(abs(sumx[l])==1&&sumy[l]==1)
        {
            if(sumx[l+1]<0||(sumx[l+1]==0&&sumx[l+2]<0))
                printf("x - ");
            else
                printf("x + ");
        }
        else if(abs(sumx[l])==1&&sumy[l]!=1)
        {
            if(sumx[l+1]<0||(sumx[l+1]==0&&sumx[l+2]<0))
                printf("x^%d - ",sumy[l]);
            else
                printf("x^%d + ",sumy[l]);
        }
        else if(abs(sumx[l])!=1&&sumy[l]==1&&sumx[l]!=0)
        {
            if(sumx[l+1]<0||(sumx[l+1]==0&&sumx[l+2]<0))
                printf("%dx - ",abs(sumx[l]));
            else
                printf("%dx + ",abs(sumx[l]));
        }
        else if(abs(sumx[l])!=1&&sumy[l]!=1&&sumx[l]!=0)
        {
            if(sumx[l+1]<0||(sumx[l+1]==0&&sumx[l+2]<0))
                printf("%dx^%d - ",abs(sumx[l]),sumy[l]);
            else
                printf("%dx^%d + ",abs(sumx[l]),sumy[l]);
        }
        l++;
    }
}
void multiplication(int *sumx,int *sumy)
{
    int i,j,k=0,l=0,m,n,u,o,g,q,temp1,temp2,mul1[100]={0},mul2[100]={0};
    for(i=0;i<10;i++)
    {
        for(j=10;j<20;j++)
        {
            mul1[k]=sumx[i]*sumx[j];
            mul2[k]=sumy[i]+sumy[j];
            k++;
        }
    }
    for(m=0;m<100;m++)
    {
        for(n=m;n<100;n++)
        {
            if((*(mul2+n)>*(mul2+m))||((*(mul2+n)==*(mul2+m))&&(*(mul1+n)!=0)))
            {
                temp1=*(mul2+n);
                temp2=*(mul1+n);
                *(mul2+n)=*(mul2+m);
                *(mul1+n)=*(mul1+m);
                *(mul2+m)=temp1;
                *(mul1+m)=temp2;
            }
        }
    }
    for(u=0;u<99;u++)
    {
        if(*(mul2+u)==*(mul2+u+1))
        {
            *(mul1+u)=*(mul1+u)+*(mul1+u+1);
            *(mul1+u+1)=0;
        }
    }
    for(g=99;g>=0;g--)
    {
        if(mul1[g]!=0)
        {
            q=mul2[g];
            break;
        }
    }
    if(*(mul1)<0)
        printf("-");
    while(mul1[l]!=0||mul2[l]!=0)
    {
        if((mul1[l+1]==0)&&(mul2[l+1]==q)&&(mul2[l]==1)&&(mul1[l]!=0))
            printf("%dx\n",abs(mul1[l]));
        else if((mul1[l+1]==0)&&(mul2[l+1]==q)&&(mul2[l]!=0)&&(mul1[l]!=0))
            printf("%dx^%d\n",abs(mul1[l]),mul2[l]);
        else if((mul1[l+1]==0)&&(mul2[l+1]==q)&&(mul2[l]==0)&&(mul1[l]!=0))
            printf("%d\n",abs(mul1[l]));
        else if(abs(mul1[l]==1)&&mul2[l]==1)
        {
            if(mul1[l+1]<0||(mul1[l+1]==0&&mul1[l+2]<0))
                printf("x - ");
            else
                printf("x + ");
        }
        else if(abs(mul1[l]==1)&&mul2[l]!=1)
        {
            if(mul1[l+1]<0||(mul1[l+1]==0&&mul1[l+2]<0))
                printf("x^%d - ",mul2[l]);
            else
                printf("x^%d + ",mul2[l]);
        }
        else if(abs(mul1[l])!=1&&mul2[l]==1&&mul1[l]!=0)
        {
            if(mul1[l+1]<0||(mul1[l+1]==0&&mul1[l+2]<0))
                printf("%dx - ",abs(mul1[l]));
            else
                printf("%dx + ",abs(mul1[l]));
        }
        else if(abs(mul1[l])!=1&&mul2[l]!=1&&mul1[l]!=0)
        {
            if(mul1[l+1]<0||(mul1[l+1]==0&&mul1[l+2]<0))
                printf("%dx^%d - ",abs(mul1[l]),mul2[l]);
            else
                printf("%dx^%d + ",abs(mul1[l]),mul2[l]);
        }
        l++;
    }
}
main()
{
    char c;
    char all1[50]={0},all2[50]={0};
    int i=0,u=0,j,k=0,l=0,m=0,n=0,xx;
    int x1[10]={0},y1[10]={0},x2[10]={0},y2[10]={0},sumx[20]={0},sumy[20]={0};
    scanf("%c",&c);
    while(all1[i]!='\n')
    {
        if(i==0)
            scanf("%c",all1);
        i++;
        scanf("%c",all1+i);
    }
    while(all2[u]!='\n')
    {
        u++;
        scanf("%c",all2+u);
    }
    for(j=0;j<49;j++)
    {
        if(((isdigit(all1[j]))&&(all1[j+1]=='x'))||((isdigit(all1[j]))&&(all1[j+1]=='\n'))||((all1[j]=='x')&&!(isdigit(all1[j-1]))&&((all1[j+1]=='^')||(all1[j+1]==' ')||(all1[j+1]=='\n'))))
        {
            if((all1[j]=='x')&&!(isdigit(all1[j-1]))&&((all1[j+1]=='^')||(all1[j+1]==' ')||(all1[j+1]=='\n'))&&(all1[j-2]=='-'))
                {x1[k]=-1;}
            else if((all1[j]=='x')&&!(isdigit(all1[j-1]))&&((all1[j+1]=='^')||(all1[j+1]==' ')||(all1[j+1]=='\n')))
                {x1[k]=1;}
            else if((all1[j-1]=='-')||(all1[j-2]=='-'))
                {x1[k]=-1*(all1[j]-48);}
            else
                {x1[k]=all1[j]-48;}
            k++;
        }
        if(((isdigit(all1[j]))&&(all1[j-1]=='^'))||((all1[j]=='x')&&((all1[j+1]==' ')||(all1[j+1]=='\n'))))
        {
            if((all1[j]=='x')&&((all1[j+1]==' ')||(all1[j+1]=='\n')))
                {y1[l]=1;}
            else
                {y1[l]=all1[j]-48;}
            l++;
        }
        if(((isdigit(all2[j]))&&(all2[j+1]=='x'))||((isdigit(all2[j]))&&(all2[j+1]=='\n'))||((all2[j]=='x')&&!(isdigit(all2[j-1]))&&((all2[j+1]=='^')||(all2[j+1]==' ')||(all2[j+1]=='\n'))))
        {
            if((all2[j]=='x')&&!(isdigit(all2[j-1]))&&((all2[j+1]=='^')||(all2[j+1]==' ')||(all2[j+1]=='\n'))&&(all2[j-2]=='-'))
                {x2[m]=-1;}
            else if((all2[j]=='x')&&!(isdigit(all2[j-1]))&&((all2[j+1]=='^')||(all2[j+1]==' ')||(all2[j+1]=='\n')))
                {x2[m]=1;}
            else if((all2[j-1]=='-')||(all2[j-2]=='-'))
                {x2[m]=-1*(all2[j]-48);}
            else
                {x2[m]=all2[j]-48;}
            m++;
        }
        if(((isdigit(all2[j]))&&(all2[j]!=0)&&(all2[j-1]=='^'))||((all2[j]=='x')&&((all2[j+1]==' ')||(all2[j+1]=='\n'))))
        {
            if((all2[j]=='x')&&((all2[j+1]==' ')||(all2[j+1]=='\n')))
                {y2[n]=1;}
            else
                {y2[n]=all2[j]-48;}
            n++;
        }
    }
    for(xx=0;xx<10;xx++)
    {
        sumx[xx]=x1[xx];
        sumy[xx]=y1[xx];
        sumx[xx+10]=x2[xx];
        sumy[xx+10]=y2[xx];
    }
    if(c=='+')
        add(sumx,sumy);
    else if(c=='-')
        subtraction(sumx,sumy);
    else
        multiplication(sumx,sumy);
}
