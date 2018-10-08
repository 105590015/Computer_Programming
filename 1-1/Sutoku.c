#include<stdio.h>
int row(int *sutoku,int n,int *a)
{
    int text[9]={1,2,3,4,5,6,7,8,9},i,j,k,m=0;
    for(i=0;i<9;i++)
    {
        for(k=0;k<9;k++)
        {
            if(*(sutoku+n*9+i)==text[k])
            text[k]=0;
        }
    }
    for(j=0;j<9;j++)
    {
        if(text[j]!=0)
        {
            *a=text[j];
            m++;
        }
    }
    if(m==1) return 1;
    else     return 0;
}
int row2(int *sutoku,int n,int *a)
{
    int text[9]={1,2,3,4,5,6,7,8,9},i,j,k,m=0;
    for(i=0;i<9;i++)
    {
        for(k=0;k<9;k++)
        {
            if(*(sutoku+i*9+n)==text[k])
            text[k]=0;
        }
    }
    for(j=0;j<9;j++)
    {
        if(text[j]!=0)
        {
            *a=text[j];
            m++;
        }
    }
    if(m==1) return 1;
    else     return 0;
}
main()
{
    int sutoku[9][9]={0},in,i,j,a,index=100000000;
    for(i=0;i<9;i++)
    {
        scanf("%d",&in);
        for(j=0;j<9;j++)
        {
            sutoku[i][j]=(in/index)%10;
            index/=10;
        }
        index=100000000;
    }
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(sutoku[i][j]==0&&row(sutoku,i,&a)==1)
            {
                printf("%d %d %d\n",i,j,a);
                sutoku[i][j]=a;
            }
        }
    }
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(sutoku[i][j]==0&&row2(sutoku,j,&a)==1)
            {
                printf("%d %d %d\n",i,j,a);
                sutoku[i][j]=a;
            }
        }
    }
}
