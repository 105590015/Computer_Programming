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
    for(i=0;i<13;i++)/*�q�Ѯv���Ĥ@���@�}�l*/
    {
        if(t[tn-65][i]!='0'&&s[t[tn-65][i]-91+(n/2)][k]==tn)/*�����@���ର��l�ơA�B���ǥͦb��k���@�Ǥ]�n�O���Ѯv*/
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
    for(u=0;u<13;u++)/*��l�ƱƧǦn�����*/
        ok[u]='0';
    for(k=0;k<n/2;k++)/*�q�C�Ӿǥͪ��Ĥ@���@s[i][0]�}�l��*/
    {
        for(i=0;i<n/2;i++)/*��i�Ӿǥ�*/
        {
            for(j=0;j<n/2;j++)/*��j�Ӿǥ�*/
            {
                if(s[i][k]==s[j][k]&&s[i][k]!='0')/*�p����@�Pi�ǥͬۦP���ƶq�Bi�ǥͧ��@���ର��l��*/
                    com++;
            }
            if(com==1&&ok[i]=='0')/*�u�P�ۤv���@�ۦP�A�B�٨S���T�w�Ѯv*/
            {
                ok[i]=s[i][k];/*�����@�N�Oi�Ǫ��Ѯv*/
                Delete(s,s[i][k],n);/*�b�ǥͰ}�C���R�h����諸�Ѯv*/
                Delete(t,91-(n/2)+i,n);/*�b�Ѯv�}�C���R�h�w���Ѯv���ǥ�*/
            }
            else if(ok[i]=='0'&&s[i][k]!=ok[0]&&s[i][k]!=ok[1]&&s[i][k]!=ok[2]&&s[i][k]!=ok[3]&&s[i][k]!=ok[4]&&s[i][k]!=ok[5]&&s[i][k]!=ok[6]
                    &&s[i][k]!=ok[7]&&s[i][k]!=ok[8]&&s[i][k]!=ok[9]&&s[i][k]!=ok[10]&&s[i][k]!=ok[11]&&s[i][k]!=ok[12])
                    /*���L�H�Pi�ǥͧ��@���ơA��i�ǥ��٨S���T�w���Ѯv�A�B���Ѯv�]�����T�w���ǥ�*/
            {
                c=Compare(s,t,s[i][k],n,k);/*��s[i][k]�Ѯv���}�C�P�_�����w���Ӿǥ�*/
                ok[c-91+(n/2)]=s[i][k];/*�N�Ѯv�Ƶ������w���ǥ�*/
                Delete(s,s[i][k],n);
                Delete(t,c,n);
            }
            Turn(ok,s,t);/*����K�P�_�N�H�t��n���Ѯv�B�ǥͰ}�C��l��*/
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
    for(i=0;i<13;i++)/*��l�ƾǥ͡B�Ѯv���@�ǰ}�C*/
    {
        for(j=0;j<13;j++)
        {
            student[i][j]='0';
            teacher[i][j]='0';
        }
    }
    while(c!='\n')/*���J�Ĥ@�վǥͧ��@��ƨíp��H��=n/2*/
    {
        scanf("%c",&c);
        if(c!=','&&c!='\n')
            student[0][y++]=c;
        n++;
    }
    for(i=1;i<n/2;i++)/*���J�ĤG�հ_�ǥͧ��@���*/
        MakeArray(student,i);
    for(j=0;j<n/2;j++)/*���J�Ѯv���@���*/
        MakeArray(teacher,j);
    Judge(student,teacher,n);
}
