#include<stdio.h>
void Judge(int internet[20][4],char name[20][20],int p,int n)
{
    int point[20]={0},i,j=1;
    for(i=p+1;i<n;i++)
    {
        if(internet[i][0]<256&&internet[i][1]<256&&internet[i][2]<256&&internet[i][3]<256&&
           internet[i][0]==internet[p][0]&&internet[i][1]==internet[p][1])
        {
            point[0]=p;
            point[j++]=i;
            internet[i][0]=-1;
            internet[i][1]=-1;
            internet[i][2]=-1;
            internet[i][3]=-1;
        }
    }
    if(j==2)
        printf("machines %s and %s are on the same local network.\n",name[point[0]],name[point[1]]);
    else if(j>2)
    {
        printf("machines ");
        for(i=0;i<j-2;i++)
            printf("%s, ",name[point[i]]);
        printf("%s and %s are on the same local network.\n",name[point[j-2]],name[point[j-1]]);
    }
}
void DeleteSpace(char name[20])
{
    int i;
    for(i=0;i<20;i++)
        if(name[i]==' ')
            name[i]='\0';
}
main()
{
    int internet[20][4]={0},i,j=0;
    char name[20][20]={'\0'},c;
    while(1)
    {
        for(i=0;i<4;i++)
            scanf("%d%c",&internet[j][i],&c);
        scanf("%[^\n]",name[j]);
        DeleteSpace(name[j]);
        if(internet[j][0]==0&&internet[j][1]==0&&internet[j][2]==0&&internet[j][3]==0&&
           name[j][0]=='n'  &&name[j][1]=='o'  &&name[j][2]=='n'  &&name[j][3]=='e')
            break;
        j++;
    }
    for(i=0;i<j;i++)
    {
        if(internet[i][0]<256&&internet[i][1]<256&&internet[i][2]<256&&internet[i][3]<256&&
           internet[i][0]>-1 &&internet[i][1]>-1 &&internet[i][2]>-1 &&internet[i][3]>-1)
            Judge(internet,name,i,j);
    }
    for(i=0;i<j;i++)
    {
        if(internet[i][0]>255||internet[i][1]>255||internet[i][2]>255||internet[i][3]>255)
            printf("machine %s is error ip\n",name[i]);
    }
}
