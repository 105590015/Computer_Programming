#include<stdio.h>
int BinaryToDecimal(char in[])
{
    int i,sum=0,index=1;
    for(i=7;i>-1;i--)
    {
        sum+=(in[i]-48)*index;
        index*=2;
    }
    return sum;
}
int Recursion(int sum)
{
    if(sum==0||sum==1)
        return 0;
    else if(sum%2==0)
        return Recursion(sum/2)+1;
    else if(sum%2!=0)
        return Recursion((sum+1)/2)+1;
}
void Print(int decimal)
{
    char out[12]="00000000000";
    int i,index=1024;
    for(i=0;i<11;i++)
    {
        if(decimal>=index)
        {
            out[i]='1';
            decimal-=index;
        }
        index/=2;
    }
    printf("%s\n",out);
}
main()
{
    int judge=0,sum,all=0,i;
    char in[8]={'\0'};
    while(judge!=-1)
    {
        scanf(" %[^\n]",in);
        sum=BinaryToDecimal(in);
        for(i=0;i<=sum;i++)
            all+=Recursion(i);
        Print(all);
        scanf("%d",&judge);
        all=0;
    }
}
