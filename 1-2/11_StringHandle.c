#include<stdio.h>
#include<string.h>
void print(char s[30][20],int which[10],int time,char word[20])/*���*/
{
    int i,j,k,l;
    for(i=0;i<10,which[i]<30;i++)
    {
        for(j=time;j>0;j--)/*��ܥ���etime��*/
            if(which[i]-j>=0)
                printf("%s ",s[which[i]-j]);
        for(l=0;l<20,word[l]!='\0';l++)/*��ܥؼг�r�B�ର�j�g*/
        {
            if(word[l]>96&&word[l]<123)
                printf("%c",word[l]-32);
            else
                printf("%c",word[l]);
        }
        printf(" ");
        for(k=1;k<=time;k++)/*��ܥk���time��*/
            if(which[i]+k<30)
                printf("%s ",s[which[i]+k]);
        printf("\n");
    }
}
int Compare(char s[30][20],int which[10],int i,int j,int t,char LR)/*����r��j�p*/
{
    int k=1;
    if(LR=='L')
    {
        for(k=1;k<=t;k++)
        {
            if(which[i]-k>-1&&which[j]-k<0)/*s[which[i]]�٦��e������r�A��s[which[j]]�S���A��s[which[i]]>s[which[j]]*/
                return 1;
            else if(which[i]-k<0&&which[j]-k>-1)/*s[which[i]]�S���e������r�A��s[which[j]]�٦��A��s[which[i]]<s[which[j]]*/
                return 0;
            else if(strcmp(s[which[i]-k],s[which[j]-k])>0)
                return 1;
            else if(strcmp(s[which[i]-k],s[which[j]-k])<0)
                return 0;
        }
        return 0;
    }
    else if(LR=='R')
    {
        for(k=1;k<=t;k++)
        {
            if(which[i]+k<31&&which[j]+k>30)/*s[which[i]]�٦��᭱����r�A��s[which[j]]�S���A��s[which[i]]>s[which[j]]*/
                return 1;
            else if(which[i]+k>30&&which[j]+k<31)/*s[which[i]]�S���᭱����r�A��s[which[j]]�٦��A��s[which[i]]<s[which[j]]*/
                return 0;
            else if(strcmp(s[which[i]+k],s[which[j]+k])>0)
                return 1;
            else if(strcmp(s[which[i]+k],s[which[j]+k])<0)
                return 0;
        }
        return 0;
    }
}
void Sort(char s[30][20],int which[10],int time,char LR)/*�̤p��j�Ƨ�*/
{
    int i,j,temp;
    for(i=0;i<10,which[i]<30;i++)
        for(j=i;j<10,which[j]<30;j++)
            if(Compare(s,which,i,j,time,LR))
            {
                temp=which[i];
                which[i]=which[j];
                which[j]=temp;
            }
}
void FindWord(char s[30][20],char word[20],int time,char LR)/*��X�ؼг�r�bs�����ӧǦC��A�ƦC��X���ǡA�ƦC�����*/
{
    int i,j,k=0,index[30]={0},which[10]={30,30,30,30,30,30,30,30,30,30};/*index[i]=1��s[i]�r�ꬰ�ؼг�r�Awhich��s[i]�bi����h�֮ɬ��ؼг�r*/
    for(i=0;i<30,s[i][0]!='\0';i++)
        if(strcmp(s[i],word)==0)
            index[i]=1;
    for(i=0;i<30;i++)
        if(index[i]==1)
            which[k++]=i;
    Sort(s,which,time,LR);
    print(s,which,time,word);
}
void Change(char s[30][20],char word[20])/*s�Mword�}�C������ƥ����ন�p�g*/
{
    int i,j;
    for(i=0;i<30,s[i][0]!='\0';i++)
        for(j=0;j<20,s[i][j]!='\0';j++)
            if(s[i][j]<91&&s[i][j]>64)
                s[i][j]+=32;
    for(i=0;i<20;i++)
        if(word[i]<91&&word[i]>64)
            word[i]+=32;
}
main()
{
    char s[30][20]={'\0'},in[150]={'\0'},word[20]={'\0'},LR;/*in�}�C�s��Ӥ峹�As�}�C�N�峹������r�̧�s[0].s[1]...���}�s�J�Aword�s�ؼг�r*/
    int time,i,j=0,k=0;
    scanf("%s %d %c %[^\n]",word,&time,&LR,in);
    for(i=0;i<150,in[i]!='\0';i++)
    {
        if(in[i]==' ')
        {
            s[j][k]='\0';
            j++;
            k=0;
        }
        else
            s[j][k++]=in[i];
    }
    Change(s,word);
    FindWord(s,word,time,LR);
}
