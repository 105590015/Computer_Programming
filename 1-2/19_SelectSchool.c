#include<stdio.h>
#include<string.h>
void Initializer(char data[10][30])
{
    int i,j;
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            data[i][j]='\0';
}
void Judge(char need[10][30],char schol[10][30])
{
    int i,j,same=0,time=0;
    for(i=0;i<10,need[i][0]!='\0';i++)
    {
        time++;
        for(j=0;j<10,schol[j][0]!='\0';j++)
            if(strcmp(need[i],schol[j])==0)
                same++;
        if(need[i][0]=='+'||need[i+1][0]=='\0')
        {
            if(need[i][0]=='+')
                time--;
            if(same==time)
                printf("%s ",schol[0]);
            time=0;
            same=0;
        }
    }
}
void Cut2(char data[30],char target[10][30])
{
    int i,j=0,k=0;
    for(i=0;i<30,data[i]!='\0';i++)
    {
        if(data[i]!=' ')
        {
            target[j][k++]=data[i];
            if(data[i+1]==' ')
            {
                target[j][k]='\0';
                j++;
                k=0;
            }
        }
    }
}
void Cut1(char data[30],char target[10][30])
{
    int i,j=0,k=0;
    for(i=0;i<30,data[i]!='\0';i++)
    {
        if(data[i]!=' ')
        {
            target[j][k++]=data[i];
            if(k==2||data[i]=='+')
            {
                target[j][k]='\0';
                j++;
                k=0;
            }
        }
    }
}
main()
{
    int n,m,i,j;
    char school[10][30]={'\0'},has[10][30]={'\0'},need[10][30]={'\0'},schol[10][30]={'\0'};
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf(" %[^\n]",school[i]);
    scanf("%d",&m);
    for(i=0;i<m;i++)
        scanf(" %[^\n]",has[i]);
    for(i=0;i<m;i++)
    {
        Cut1(has[i],need);
        for(j=0;j<n;j++)
        {
            Cut2(school[j],schol);
            Judge(need,schol);
            Initializer(schol);
        }
        Initializer(need);
        printf("\n");
    }
}
