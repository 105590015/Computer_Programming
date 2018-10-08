#include <stdio.h>
void generatedata(int data[])
{
    int i,j,k,l,size=0;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            for(k=0;k<10;k++)
            {
                for(l=0;l<10;l++)
                {
                    if(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l)
                    {
                        *(data+size)=i*1000+j*100+k*10+l;
                        size++;
                    }
                }
            }
        }
    }
}
int judge(int data[],int *output)
{
    int a=0,i;
    for(i=0;i<9999;i++)
    {
        if(data[i]!=0)
        {
            a++;
            *output=data[i];
        }
    }
    if(a==1)
        return 1;
    else
        return 0;
}
void Remove(int i,int A,int B,int data[])
{
    int j;
    for(j=0;j<9999;j++)
    {
        if(AB(data[j],i,A,B)==0)
            data[j]=0;
    }
}
int AB(int data,int i,int A,int B)
{
    int i1,i2,i3,i4,d1,d2,d3,d4,A2=0,B2=0;
    i1=i/1000;
    i2=(i/100)%10;
    i3=(i/10)%10;
    i4=i%10;
    d1=data/1000;
    d2=(data/100)%10;
    d3=(data/10)%10;
    d4=data%10;
    if(i1==d1)                       A2++;
    else if(i1==d2||i1==d3||i1==d4)  B2++;
    if(i2==d2)                       A2++;
    else if(i2==d1||i2==d3||i2==d4)  B2++;
    if(i3==d3)                       A2++;
    else if(i3==d1||i3==d2||i3==d4)  B2++;
    if(i4==d4)                       A2++;
    else if(i4==d1||i4==d2||i4==d3)  B2++;
    if(A2==A&&B2==B)
        return 1;
    else
        return 0;
}
main()
{
    int i,j,A,B,input,*output;
    int data[9999]={0};
    char c1,c2,c3;
    generatedata(data);
    for(j=0;j<10;j++)
    {
        scanf("%d%c%d%c%d%c",&i,&c1,&A,&c2,&B,&c3);
        /*printf("%d,%d,%d\n",i,A,B);*/
        Remove(i,A,B,data);
        if(judge(data,&output)==1)
        {
            if(output<1000)
                printf("0%d",output);
            else
                printf("%d",output);
            break;
        }
    }
}
