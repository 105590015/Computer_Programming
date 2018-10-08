#include<stdio.h>
#include<string.h>
void Sort(char s[20][10],int t[20])/*排序*/
{
    int instead[20]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},i,j,k,temp1,temp2;
    for(i=0;i<20;i++)
        for(j=i;j<20;j++)
        {
            if(t[i]<t[j]&&t[j]!=0)
            {
                temp1=t[i];
                temp2=instead[i];
                t[i]=t[j];
                instead[i]=instead[j];
                t[j]=temp1;
                instead[j]=temp2;
            }
            else if(t[i]==t[j]&&strcmp(s[instead[i]],s[instead[j]])>0)
            {
                temp1=t[i];
                temp2=instead[i];
                t[i]=t[j];
                instead[i]=instead[j];
                t[j]=temp1;
                instead[j]=temp2;
            }
        }
    for(k=0;k<20;k++)
        if(t[k]!=0)
            printf("%s %d\n",s[instead[k]],t[k]);
}
int Common(char in[100],char s[20][10],int n,int i)/*判斷是否與指定的第i個虛詞相同*/
{
    int j,result=1;
    for(j=0;j<10,s[i][j]!='\0';j++)
        if(in[n+j]!=s[i][j])
                result=0;
    if(in[n+j]!=' ')
        result=0;
    return result;
}
int Judge(char in[100],char s[20][10],int t[20],int n)/*計算虛詞的出現次數*/
{
    int i,j;
    for(i=0;i<20,s[i][0]!='\0';i++)
        if(Common(in,s,n,i))
        {
            t[i]++;
            return 1;
        }
    return 0;
}
void Select(char in[100],char s[20][10])/*顯示.計算不是虛詞的部分*/
{
    char ok[100]={'\0'};
    int time[20]={0},i,j=0,k=0,sum=0;
    for(i=0;i<100,in[i]!='\0';i++)
        if((i==0||in[i-1]==' ')&&!Judge(in,s,time,i))
        {
            while(in[i+j]!=' '&&in[i+j]!='\0')
                ok[k++]=in[i+j++];
            ok[k++]=' ';
            j=0;
            sum++;
        }
    ok[k]='\0';
    printf("%s\n%d\n",ok,sum);
    Sort(s,time);
}
main()
{
    char s[20][10]={'\0'},in[100]={'\0'};
    int i=0;
    while(s[i-1][0]!='-')
        scanf("%s",s[i++]);
    scanf(" %[^\n]",in);
    Select(in,s);
}
