#include<stdio.h>
void Scan(char s[])
{
    char c='0';
    int i=0;
    while(c!='\n')
    {
        scanf("%c",&c);
        s[i++]=c;
    }
    while(i!=199)
        s[i++]='\0';
}
int pow(int a,int j)
{
    int i,sum=1;
    for(i=0;i<j;i++)
        sum*=a;
    return sum;
}
int Compute(int math[10][10])
{
    int sum=0,change=0,start=0,i,j;
    for(i=0;i<10;i++)
    {
        for(j=3;j>=0;j--)
        {
            if(math[i][j]!=0||start==1)
            {
                start=1;
                change+=math[i][j]*pow(10,j);
            }
        }
        //printf("%d\n",change);
        sum+=change;
        start=0;
        change=0;
    }
    //printf("%d",sum);
    return sum;
}
void Judge1(char s[])
{
    int math[10][10]={0},i,x=0,y=0;
    for(i=0;i<200;i++)
    {
        if(isdigit(s[i]))
            math[x][y++]=s[i]-48;
        else if(isdigit(s[i-1])&&!isdigit(s[i]))
        {
            x++;
            y=0;
        }
    }
    printf("%d",Compute(math));
}
void Judge2(char s[])
{
    int frequency[200]={0},i,j,k,l,big=0,time,target=4;
    for(i=0;i<200;i++)
        for(j=0;j<200;j++)
        {
            if(s[i]==s[j]&&j<i)
            {
                frequency[i]=0;
                break;
            }
            else if(s[i]==s[j])
                frequency[i]++;
        }
    for(k=0,time=0;k<200,time<4;k++)
    {
        for(l=k;l<200;l++)
            if(frequency[k]<frequency[l]&&frequency[l]<10)
                big++;
        if(big<target&&frequency[k]<10)
        {
            printf("%d",frequency[k]);
            time++;
            target--;
        }
        big=0;
    }
}
main()
{
    char s1[200],s2[200];
    Scan(s1);
    Scan(s2);
    Judge1(s1);
    Judge2(s2);
}
