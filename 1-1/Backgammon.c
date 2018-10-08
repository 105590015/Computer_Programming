#include<stdio.h>
int row(char *backgammon,int x,int y)
{
    int x2=x+2,s1=0,s2=0;
    x-=2;
    while(x>=0)
    {
        if(*(backgammon+20*y+x)=='1')
            s1++;
        else break;
        x-=2;
    }
    while(x2<=19)
    {
        if(*(backgammon+20*y+x2)=='1')
            s2++;
        else break;
        x2+=2;
    }
    //printf("s1=%d+%d\n",s1,s2);
    if(s1+s2==4) return 1;
    else         return 0;
}
int column(char *backgammon,int x,int y)
{
    int y2=y+1,s1=0,s2=0;
    y--;
    while(y>=0)
    {
        if(*(backgammon+20*y+x)=='1')
            s1++;
        else break;
        y--;
    }
    while(y2<=9)
    {
        if(*(backgammon+20*y2+x)=='1')
            s2++;
        else break;
        y2++;
    }
    //printf("s2=%d+%d\n",s1,s2);
    if(s1+s2==4) return 1;
    else         return 0;
}
int rightslash(char *backgammon,int x,int y)
{
    int x2=x+2,y2=y+1,s1=0,s2=0;
    x-=2;
    y--;
    while(y>=0&&x>=0)
    {
        if(*(backgammon+20*y+x)=='1')
            s1++;
        else break;
        x-=2;
        y--;
    }
    while(y2<=9&&x2<=19)
    {
        if(*(backgammon+20*y2+x2)=='1')
            s2++;
        else break;
        x2+=2;
        y2++;
    }
    //printf("s3=%d+%d\n",s1,s2);
    if(s1+s2==4) return 1;
    else         return 0;
}
int leftslash(char *backgammon,int x,int y)
{
    int x2=x+2,y2=y+1,s1=0,s2=0;
    x-=2;
    y--;
    while(y>=0&&x2<=19)
    {
        if(*(backgammon+20*y+x2)=='1')
            s1++;
        else break;
        x2+=2;
        y--;
    }
    while(y2<=9&&x>=0)
    {
        if(*(backgammon+20*y2+x)=='1')
            s2++;
        else break;
        x-=2;
        y2++;
    }
    //printf("s4=%d+%d\n",s1,s2);
    if(s1+s2==4) return 1;
    else         return 0;
}
main()
{
    int i,j,k;
    char backgammon[10][20]={'0'},c;
    for(i=0;i<10;i++)
    {
        scanf("%[^\n]",backgammon[i]);
        scanf("%c",&c);
    }
    for(j=0;j<10;j++)
    {
        for(k=0;k<20;k+=2)
        {
            if(row(backgammon,k,j)==1||column(backgammon,k,j)==1||rightslash(backgammon,k,j)==1||leftslash(backgammon,k,j)==1)
                printf("%d %d\n",j,k/2);
        }
    }
}
