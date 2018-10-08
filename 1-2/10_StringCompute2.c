#include<stdio.h>
#include<string.h>
void Sort(char s[20][10],int t[20])
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
void Compute(char s[20][10])
{
    int time[20]={0},i,j;
    for(i=0;i<20,s[i][0]!='\0';i++)
    {
        for(j=0;j<20,s[j][0]!='\0';j++)
        {
            if(strcmp(s[i],s[j])==0&&j<i)
            {
                time[i]==0;
                break;
            }
            else if(strcmp(s[i],s[j])==0)
                time[i]++;
        }
    }
    Sort(s,time);
}
void Delete(char s[20][10],char w1[10],char w2[10])
{
    int i;
    for(i=0;i<20,s[i][0]!='\0';i++)
        if(strcmp(s[i],w1)!=0)
            printf("%s ",s[i]);
    printf("\n");
}
void Insert(char s[20][10],char w1[10],char w2[10])
{
    int i;
    for(i=0;i<20,s[i][0]!='\0';i++)
    {
        if(strcmp(s[i],w1)!=0)
            printf("%s ",s[i]);
        else
            printf("%s %s ",w2,w1);
    }
    printf("\n");
}
void Replace(char s[20][10],char w1[10],char w2[10])
{
    int i;
    for(i=0;i<20,s[i][0]!='\0';i++)
    {
        if(strcmp(s[i],w1)!=0)
            printf("%s ",s[i]);
        else
            printf("%s ",w2);
    }
    printf("\n");
}
main()
{
    char in[100]={'\0'},str[20][10]={'\0'},word1[10]={'\0'},word2[10]={'\0'};
    int i,j=0,k=0,l;
    scanf("%[^\n] %s %s",in,word1,word2);
    for(i=0;i<100,in[i]!='\0';i++)
    {
        if(in[i]==' ')
        {
            str[j][k]='\0';
            j++;
            k=0;
        }
        else
            str[j][k++]=in[i];
    }
    Replace(str,word1,word2);
    Insert(str,word1,word2);
    Delete(str,word1,word2);
    Compute(str);
}
