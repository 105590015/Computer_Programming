#include<stdio.h>
void Turn(char ok[13],char s[13][13],char t[13][13])
{
    int i,j;
    for(i=0;i<13;i++)
    {
        if(ok[i]!='0')
        {
            for(j=0;j<13;j++)
            {
                s[i][j]='0';
                t[ok[i]-65][j]='0';
            }
        }
    }
}
char Compare(char s[13][13],char t[13][13],char tn,int n,int k)
{
    int i;
    for(i=0;i<13;i++)/*從老師的第一志願開始*/
    {
        if(t[tn-65][i]!='0'&&s[t[tn-65][i]-91+(n/2)][k]==tn)/*此志願不能為初始化，且此學生在第k志願序也要是此老師*/
            return t[tn-65][i];
    }
}
void Delete(char people[13][13],char p,int n)
{
    int i,j;
    for(i=0;i<n/2;i++)
    {
        for(j=0;j<n/2;j++)
        {
            if(people[i][j]==p)
                people[i][j]='0';
        }
    }
}
void Judge(char s[13][13],char t[13][13],int n)
{
    int com=0;
    char ok[13],c;
    int i,j,k,l,o,u,ii,jj;
    for(u=0;u<13;u++)/*初始化排序好的資料*/
        ok[u]='0';
    for(k=0;k<n/2;k++)/*從每個學生的第一志願s[i][0]開始比*/
    {
        for(i=0;i<n/2;i++)/*第i個學生*/
        {
            for(j=0;j<n/2;j++)/*第j個學生*/
            {
                if(s[i][k]==s[j][k]&&s[i][k]!='0')/*計算志願與i學生相同的數量且i學生志願不能為初始化*/
                    com++;
            }
            if(com==1&&ok[i]=='0')/*只與自己志願相同，且還沒有確定老師*/
            {
                ok[i]=s[i][k];/*此志願就是i學的老師*/
                Delete(s,s[i][k],n);/*在學生陣列中刪去不能選的老師*/
                Delete(t,91-(n/2)+i,n);/*在老師陣列中刪去已有老師的學生*/
            }
            else if(ok[i]=='0'&&s[i][k]!=ok[0]&&s[i][k]!=ok[1]&&s[i][k]!=ok[2]&&s[i][k]!=ok[3]&&s[i][k]!=ok[4]&&s[i][k]!=ok[5]&&s[i][k]!=ok[6]
                    &&s[i][k]!=ok[7]&&s[i][k]!=ok[8]&&s[i][k]!=ok[9]&&s[i][k]!=ok[10]&&s[i][k]!=ok[11]&&s[i][k]!=ok[12])
                    /*有他人與i學生志願重複，但i學生還沒有確定的老師，且此老師也未有確定的學生*/
            {
                c=Compare(s,t,s[i][k],n,k);/*到s[i][k]老師的陣列判斷較喜歡哪個學生*/
                ok[c-91+(n/2)]=s[i][k];/*將老師排給較喜歡的學生*/
                Delete(s,s[i][k],n);
                Delete(t,c,n);
            }
            Turn(ok,s,t);/*為方便判斷將以配對好的老師、學生陣列初始化*/
            com=0;
        }
    }
    for(l=0;l<n/2;l++)
        printf("%c->%c\n",91-n/2+l,ok[l]);
}
void MakeArray(char person[13][13],int i)
{
    char c='0';
    int x=0;
    while(c!='\n')
    {
        scanf("%c",&c);
        if(c!=','&&c!='\n')
            person[i][x++]=c;
    }
}
main()
{
    char student[13][13],teacher[13][13],c='0';
    int i,j,n=0,y=0;
    for(i=0;i<13;i++)/*初始化學生、老師志願序陣列*/
    {
        for(j=0;j<13;j++)
        {
            student[i][j]='0';
            teacher[i][j]='0';
        }
    }
    while(c!='\n')/*掃入第一組學生志願資料並計算人數=n/2*/
    {
        scanf("%c",&c);
        if(c!=','&&c!='\n')
            student[0][y++]=c;
        n++;
    }
    for(i=1;i<n/2;i++)/*掃入第二組起學生志願資料*/
        MakeArray(student,i);
    for(j=0;j<n/2;j++)/*掃入老師志願資料*/
        MakeArray(teacher,j);
    Judge(student,teacher,n);
}
