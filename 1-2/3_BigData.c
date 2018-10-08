#include<stdio.h>
int Compute(int data[190][3],int input[],int k)
{
    int i,j,m=0;
    for(i=0;i<4;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if((input[i]==data[k][0]&&input[j]==data[k][1])||(input[j]==data[k][0]&&input[i]==data[k][1]))
                m++;
        }
    }
    return m+data[k][2];
}
void Judge(int data[190][3],int input[],int *o1,int *o2,int *o3)
{
    int k,l,max=0,maxX,maxY;
    for(k=0;k<190;k++)
        data[k][2]=Compute(data,input,k);
    for(l=0;l<190;l++)
    {
        if(data[l][2]>max)
        {
            max=data[l][2];
            maxY=data[l][1];
            maxX=data[l][0];
        }
    }
    *o1=maxX;
    *o2=maxY;
    *o3=max;
    /*for(k=0;k<190;k++)
            printf("%d,%d,%d\n",data[k][0],data[k][1],data[k][2]);*/
}
main()
{
    int input[5]={0},data[190][3]={0},n,i,j,k,l,o,x=0,y=0,*output1,*output2,*output3;
    char enter,s[24]={'0'};
    scanf("%d%c",&n,&enter);
    for(i=1;i<20;i++)
    {
        for(j=i+1;j<21;j++)
        {
            data[y][0]=i;
            data[y][1]=j;
            y++;
        }
    }
    for(k=0;k<n;k++)
    {
        scanf("%s",s);
        for(l=0;l<23;l++)
        {
            if(isdigit(s[l])&&isdigit(s[l+1])&&s[l]!='0')
            {
                input[x++]=(s[l]-48)*10+(s[l+1]-48);
                l++;
            }
            else if(isdigit(s[l])&&s[l]!='0')
                input[x++]=s[l]-48;
        }
        /*printf("%d,%d,%d,%d,%d\n",input[0],input[1],input[2],input[3],input[4]);*/
        Judge(data,input,&output1,&output2,&output3);
        x=0; input[0]=0; input[1]=0; input[2]=0; input[3]=0; input[4]=0;
        for(o=0;o<24;o++)
            s[o]='0';
    }
    printf("%d,%d,%d",output1,output2,output3);
}
