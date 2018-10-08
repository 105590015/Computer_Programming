#include<stdio.h>
#include<string.h>
typedef struct
{
    int firstornot;
    char username[9];
    char password[9];
    char mail[30];
    int voteornot;
}user_t;
typedef struct
{
    int number;
    char name[9];
    int voted;
}candidate_t;
int JudgeUsername(char username[],user_t w[],int wn)
{
    int i;
    for(i=0;i<9,username[i]!='\0';i++)
    {
        if(!(isalpha(username[i])||isdigit(username[i])))
            return 1;
    }
    for(i=0;i<wn;i++)
    {
        if(strcmp(username,w[i].username)==0)
            return 1;
    }
    return 0;
}
int JudgePassword(char password[],char username[])
{
    int i;
    for(i=0;i<9,username[i]!='\0';i++)
    {
        if(!(isalpha(username[i])||isdigit(username[i])||username[i]=='_'||username[i]=='-'||username[i]=='@'||username[i]=='%'||username[i]=='%'))
            return 1;
    }
    if(strcmp(username,password)==0)
        return 1;
    return 0;
}
int JudgeNumberAndName(int number,char name[],candidate_t c[],int cn)
{
    int i;
    for(i=0;i<cn;i++)
    {
        if(number==c[i].number)
            return 1;
        if(strcmp(name,c[i].name)==0)
            return 1;
    }
    return 0;
}
int JudegeLogin(char username[],char password[],user_t w[],int wn)
{
    int i;
    for(i=0;i<wn;i++)
    {
        if(strcmp(username,w[i].username)==0&&strcmp(password,w[i].password)==0)
            return 0;
    }
    return 1;
}
int JudgeVote(char username[],char password[],user_t w[],int wn)
{
    int i;
    for(i=0;i<wn;i++)
    {
        if(strcmp(username,w[i].username)==0&&strcmp(password,w[i].password)==0&&(w[i].firstornot==1||w[i].voteornot==1))
            return 1;
    }
    return 0;
}
int JudgeNumber(int number,candidate_t c[],int cn)
{
    int i;
    for(i=0;i<cn;i++)
    {
        if(number==c[i].number)
            return 0;
    }
    return 1;
}
void Vote(candidate_t c[],int cn,int number)
{
    int i;
    for(i=0;i<cn;i++)
    {
        if(number==c[i].number)
            c[i].voted++;
    }
}
void HaveVoted(user_t w[],int wn,char username[])
{
    int i;
    for(i=0;i<wn;i++)
    {
        if(strcmp(username,w[i].username)==0)
            w[i].voteornot=1;
    }
}
void PrintName(char name[])
{
    int i;
    for(i=0;i<9,name[i]!='\0';i++)
    {
        if(isalpha(name[i]))
            printf("%c",name[i]);
    }
    printf(",");
}
void Print(candidate_t c[],int cn)
{
    int i,haveprinted=0;
    while(haveprinted!=cn)
    {
        haveprinted++;
        for(i=0;i<cn;i++)
        {
            if(c[i].number==haveprinted)
            {
                printf("(%d,",haveprinted);
                PrintName(c[i].name);
                printf("%d)",c[i].voted);
            }
        }
        if(haveprinted!=cn)
            printf(",");
    }
    printf("\n");
}
main()
{
    user_t w[5];
    candidate_t c[5];
    int wn=0,cn=0,number,first=1;
    char username[9]={'\0'},password[9]={'\0'},mail[30]={'\0'},name[9]={'\0'},m,comma;
    scanf("%c%c",&m,&comma);
    while(1)
    {
        if(m=='A')
        {
            scanf("%[^,]%c%[^,]%c%[^\n]",username,&comma,password,&comma,mail);
            if(JudgeUsername(username,w,wn)||JudgePassword(password,username))
            {
                printf("Add user error\n");
                if(JudgeUsername(username,w,wn))      printf("username error\n");
                if(JudgePassword(password,username))  printf("password error\n");
            }
            else
            {
                printf("Add user successful\n");
                if(first==1)
                {
                    w[wn].firstornot=1;
                    first=0;
                }
                else
                    w[wn].firstornot=0;
                strcpy(w[wn].username,username);
                strcpy(w[wn].password,password);
                strcpy(w[wn].mail,mail);
                w[wn++].voteornot=0;
            }
        }
        else if(m=='M')
        {
            scanf("%[^,]%c%[^,]%c%d%c%[^\n]",username,&comma,password,&comma,&number,&comma,name);
            if(JudgeNumberAndName(number,name,c,cn))    printf("Candidate data error\n");
            if(JudegeLogin(username,password,w,wn))     printf("Login error\n");
            if(!(JudgeNumberAndName(number,name,c,cn)||JudegeLogin(username,password,w,wn)))
            {
                printf("Add candidate successful\n");
                strcpy(c[cn].name,name);
                c[cn].number=number;
                c[cn++].voted=0;
            }
        }
        else if(m=='V')
        {
            scanf("%[^,]%c%[^,]%c%d",username,&comma,password,&comma,&number);
            if(JudgeVote(username,password,w,wn))    printf("Voting error\n");
            if(JudgeNumber(number,c,cn))             printf("Candidate error\n");
            if(JudegeLogin(username,password,w,wn))  printf("Login error\n");
            if(!(JudgeVote(username,password,w,wn)||JudgeNumber(number,c,cn)||JudegeLogin(username,password,w,wn)))
            {
                printf("Voting successful\n");
                Vote(c,cn,number);
                HaveVoted(w,wn,username);
            }
        }
        else if(m=='Q')
        {
            scanf("%[^,]%c%[^\n]",username,&comma,password);
            if(JudegeLogin(username,password,w,wn))
                printf("Login error\n");
            else
                Print(c,cn);
        }
        else if(m=='E')
        {
            printf("Exit\n");
            break;
        }
        scanf("%c%c%c",&comma,&m,&comma);
    }
}
