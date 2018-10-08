#include<stdio.h>
void f1(int num[],int cs[],int pg[],int jud)
{
    int x,i;
    if(jud==1)
    {
        scanf("%d",&x);
        for(i=0;i<90;i++)
            if(num[i]==x)
                printf("%d",(cs[i]+pg[i])/2);
    }
    else if(jud==2)
    {
        scanf("%d",&x);
        for(i=0;i<90;i++)
            if(num[i]==x)
                printf("%d",cs[i]);
    }
    else if(jud==3)
    {
        scanf("%d",&x);
        for(i=0;i<90;i++)
            if(num[i]==x)
                printf("%d",pg[i]);
    }
}
void f2(int num[],int cs[],int pg[],int jud)
{
    int i,j,max=0,maxcs=0,maxpg=0;
    for(j=0;j<90;j++)
    {
        if((cs[j]+pg[j])/2>max)
            max=(cs[j]+pg[j])/2;
        if(cs[j]>maxcs)
            maxcs=cs[j];
        if(pg[j]>maxpg)
            maxpg=pg[j];
    }
    if(jud==1)
        printf("%d",max);
    else if(jud==2)
        printf("%d",maxcs);
    else if(jud==3)
        printf("%d",maxpg);
}
void f3(int num[],int cs[],int pg[],int jud)
{
    int i,j,min=100,mincs=100,minpg=100;
    for(j=0;j<90;j++)
    {
        if((cs[j]+pg[j])/2<min&&(cs[j]+pg[j])/2!=0)
            min=(cs[j]+pg[j])/2;
        if(cs[j]<mincs&&cs[j]!=0)
            mincs=cs[j];
        if(pg[j]<minpg&&pg[j]!=0)
            minpg=pg[j];
    }
    if(jud==1)
        printf("%d",min);
    else if(jud==2)
        printf("%d",mincs);
    else if(jud==3)
        printf("%d",minpg);
}
void f4(int num[],int cs[],int pg[],int jud)
{
    int k;
    if(jud==1)
    {
        for(k=0;k<90;k++)
        {
            if((cs[k]+pg[k])/2<60&&num[k]!=0&&num[k]!=-1)
                printf("%d:%d\n",num[k],(cs[k]+pg[k])/2);
        }
    }
    else if(jud==2)
        for(k=0;k<90;k++)
        {
            if(cs[k]<60&&cs[k]!=0)
                printf("%d:%d\n",num[k],cs[k]);
        }
    else if(jud==3)
        for(k=0;k<90;k++)
        {
            if(pg[k]<60&&pg[k]!=0)
                printf("%d:%d\n",num[k],pg[k]);
        }
}
void f5(int num[],int cs[],int pg[],int jud)
{
    int k;
    if(jud==1)
    {
        for(k=0;k<90;k++)
        {
            if((cs[k]+pg[k])/2>=60)
                printf("%d:%d\n",num[k],(cs[k]+pg[k])/2);
        }
    }
    else if(jud==2)
        for(k=0;k<90;k++)
        {
            if(cs[k]>=60)
                printf("%d:%d\n",num[k],cs[k]);
        }
    else if(jud==3)
        for(k=0;k<90;k++)
        {
            if(pg[k]>=60)
                printf("%d:%d\n",num[k],pg[k]);
        }
}
void f6(int num[],int cs[],int pg[],int jud)
{
    int k,fir=0,sec=0,thi=0,n1=0,n2=0,n3=0,temp1,temp2,temp3,tem1,tem2,tem3;
    if(jud==1)
    {
        for(k=0;k<90;k++)
        {
            if((cs[k]+pg[k])/2>fir)
                {temp1=sec; tem1=n2; n2=n1; sec=fir; thi=temp1; n3=tem1; fir=(cs[k]+pg[k])/2; n1=k;}
            else if((cs[k]+pg[k])/2>sec&&(cs[k]+pg[k])/2<fir)
                {thi=sec; n3=n2; sec=(cs[k]+pg[k])/2; n2=k;}
            else if((cs[k]+pg[k])/2>thi&&(cs[k]+pg[k])/2<sec)
                {thi=(cs[k]+pg[k])/2; n3=k;}
        }
        printf("1st:%d %d\n2nd:%d %d\n3rd:%d %d",num[n1],fir,num[n2],sec,num[n3],thi);
    }
    else if(jud==2)
    {
        for(k=0;k<90;k++)
        {
            if(cs[k]>fir)
                {temp2=sec; tem2=n2; n2=n1; sec=fir; thi=temp2; n3=tem2; fir=cs[k]; n1=k;}
            else if(cs[k]>sec&&cs[k]<fir)
                {thi=sec; n3=n2; sec=cs[k]; n2=k;}
            else if(cs[k]>thi&&cs[k]<sec)
                {thi=cs[k]; n3=k;}
        }
        printf("1st:%d %d\n2nd:%d %d\n3rd:%d %d",num[n1],fir,num[n2],sec,num[n3],thi);
    }
    else if(jud==3)
    {
        for(k=0;k<90;k++)
        {
            if(pg[k]>fir)
                {temp3=sec; tem3=n2; n2=n1; sec=fir; thi=temp3; n3=tem3; fir=pg[k]; n1=k;}
            else if(pg[k]>sec&&pg[k]<fir)
                {thi=sec; n3=n2; sec=pg[k]; n2=k;}
            else if(pg[k]>thi&&pg[k]<sec)
                {thi=pg[k]; n3=k;}
        }
        printf("1st:%d %d\n2nd:%d %d\n3rd:%d %d",num[n1],fir,num[n2],sec,num[n3],thi);
    }
}
void f7(int num[],int cs[],int pg[],int jud)
{
    int i,j,k,t=0,n,m,temp,temp2,temp3;
    for(i=0;i<90;i++)
    {
        for(j=i;j<90;j++)
        {
            if((cs[j]+pg[j])/2<(cs[i]+pg[i])/2&&(cs[j]+pg[j])/2!=0)
            {
                temp=num[j];
                temp2=cs[j];
                temp3=pg[j];
                num[j]=num[i];
                cs[j]=cs[i];
                pg[j]=pg[i];
                num[i]=temp;
                cs[i]=temp2;
                pg[i]=temp3;
            }
        }
        if(num[i]!=0&&num[i]!=-1)
            t++;
    }
    if(jud==1)
    {
        if(t%2==1)
        {
            printf("%d",(cs[t/2]+pg[t/2])/2);
        }
        else
        {
            printf("%d",(cs[t/2]+pg[t/2]+cs[t/2-1]+pg[t/2-1])/4);
        }
    }
    else if(jud==2)
    {
        printf("0-10:");
        for(n=0;n<90;n++)
        {
            if((cs[n]+pg[n])/2>0&&(cs[n]+pg[n])/2<=10)
                printf("*");
        }
        printf("\n");
        for(m=1;m<10;m++)
            print(m,cs,pg);
    }
}
void print(int m,int cs[],int pg[])
{
    int n;
    printf("%d-%d:",10*m+1,(m+1)*10);
    for(n=0;n<90;n++)
    {
        if((cs[n]+pg[n])/2>=10*m+1&&(cs[n]+pg[n])/2<=(m+1)*10)
            printf("*");
    }
    printf("\n");
}
main()
{
    int t=0,i,j,temp,temp2,temp3,state,jud,num[90]={0},cs[90]={0},pg[90]={0};
    scanf("%d",&num[0]);
    while(num[t]!=-1)
    {
        scanf("%d %d",&cs[t],&pg[t]);
        t++;
        scanf("%d",&num[t]);
    }
    scanf("%d %d",&state,&jud);
    for(i=0;i<90;i++)
    {
        for(j=i;j<90;j++)
        {
            if(num[j]<num[i]&&num[j]!=0&&num[j]!=-1)
            {
                temp=num[j];
                temp2=cs[j];
                temp3=pg[j];
                num[j]=num[i];
                cs[j]=cs[i];
                pg[j]=pg[i];
                num[i]=temp;
                cs[i]=temp2;
                pg[i]=temp3;
            }
        }
    }
    switch(state)
    {
    case 1:
        f1(num,cs,pg,jud);
        break;
    case 2:
        f2(num,cs,pg,jud);
        break;
    case 3:
        f3(num,cs,pg,jud);
        break;
    case 4:
        f4(num,cs,pg,jud);
        break;
    case 5:
        f5(num,cs,pg,jud);
        break;
    case 6:
        f6(num,cs,pg,jud);
        break;
    case 7:
        f7(num,cs,pg,jud);
        break;
    }
}
