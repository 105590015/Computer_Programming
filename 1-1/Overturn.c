#include <stdio.h>
void right(int *array,int n)
{
    int i,j,a[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            a[i][j]=*(array+n*i+j);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            *(array+n*i+j)=a[n-1-j][i];
    }
}
void left(int *array,int n)
{
    int i,j,a[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            a[i][j]=*(array+n*i+j);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            *(array+n*i+j)=a[j][n-1-i];
    }
}
void fold(int *array,int n)
{
    int i,j,a[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            a[i][j]=*(array+n*i+j);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            *(array+n*i+j)=a[n-1-i][j];
    }
}
main()
{
    int n,i=1,j,k;
    char instruction[80]={'\0'};
    scanf("%d",&n);
    scanf("%c",&instruction[0]);
    int array[n][n];
    for(j=0;j<n;j++)
    {
        for(k=0;k<n;k++)
            array[j][k]=j*n+k+1;
    }
    while(instruction[i]!='F')
    {
        scanf("%c",&instruction[i]);
        if(instruction[i]=='R')       right(array,n);
        else if(instruction[i]=='L')  left(array,n);
        else if(instruction[i]=='N')  fold(array,n);
        else if(instruction[i]=='F')  break;
        i++;
    }
    for(j=0;j<n;j++)
    {
        for(k=0;k<n;k++)
            printf("%d ",array[j][k]);
        printf("\n");
    }
}
