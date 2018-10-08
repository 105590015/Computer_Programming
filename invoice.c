#include <stdio.h>
void Start(char prize[8][9])
{
    printf("\n�o���I�� *~(�á���)~* ���z����\n\n");
    printf("�п�J�������X\n");
    printf("(8���)�S�O�� : ");
    Scan(prize[0],0);
    printf("(8���)�S�� : ");
    Scan(prize[1],0);
    printf("(8���)�Y��(1) : ");
    Scan(prize[2],0);
    printf("(8���)�Y��(2) : ");
    Scan(prize[3],0);
    printf("(8���)�Y��(3) : ");
    Scan(prize[4],0);
    printf("(3���)�W�}����(1) : ");
    Scan(prize[5],1);
    printf("(3���)�W�}����(2) : ");
    Scan(prize[6],1);
    printf("(3���)�W�}����(3) : ");
    Scan(prize[7],1);
}
void Clear(char input)
{
    int i;
    char garbage;
    if(input!='\n')
    {
        for(i=0;i<100;i++)
        {
            scanf("%c",&garbage);
            if(garbage=='\n')
                return;
        }
    }
}
void Scan(char input[9],int type)
{
    int i;
    while(1)
    {
        for(i=0;i<9;i++)
        {
            scanf("%c",&input[i]);
            if((i==8 && input[i]=='\n' && (type==0 || type==2)) || (i==3 && input[i]=='\n' && type==1))
                return;
            else if((input[i]=='\n' && i!=8 && type==0) || (input[i]=='\n' && i!=3 && type==1))
            {
                printf("��J���Ʀr��Ƥ��šA�Э��s��J : \n");
                Clear(input[i]);
                break;
            }
            else if(i!=8 && !isdigit(input[i]))
            {
                printf("��J�F�D�Ʀr�����X�A�Э��s��J : \n");
                Clear(input[i]);
                break;
            }
            else if(i==0 && input[i]=='0'&& type==2)
                exit(1);
        }
    }
}
int InCommon(char prize[9], char input[9])
{
    int i,common=0;
    for(i=7;i>-1;i--)
    {
        if(prize[i]==input[i])
            common++;
        else
            break;
    }
    return common;
}
void Check(char prize[8][9], char input[9])
{
    int i,common1,common2,common3;
    common1=InCommon(prize[2],input);
    common2=InCommon(prize[3],input);
    common3=InCommon(prize[4],input);
    if(InCommon(prize[0],input)==8)
        printf("������o'�S�O��'1000�U��!!!\n");
    else if(InCommon(prize[1],input)==8)
        printf("������o'�S��'200�U��!!!\n");
    else if(common1==8 || common2==8 || common3==8)
        printf("������o'�Y��'20�U��!!!\n");
    else if(common1==7 || common2==7 || common3==7)
        printf("������o'�G��'4�U��!!!\n");
    else if(common1==6 || common2==6 || common3==6)
        printf("������o'�T��'1�U��!!!\n");
    else if(common1==5 || common2==5 || common3==5)
        printf("������o'�|��'4�d��!!!\n");
    else if(common1==4 || common2==4 || common3==4)
        printf("������o'����'1�d��!!!\n");
    else if(common1==3 || common2==3 || common3==3)
        printf("������o'����'2�ʤ�!!!\n");
    else if(prize[5][0]==input[5] && prize[5][1]==input[6] && prize[5][2]==input[7])
        printf("������o'����'2�ʤ�!!!\n");
    else if(prize[6][0]==input[5] && prize[6][1]==input[6] && prize[6][2]==input[7])
        printf("������o'����'2�ʤ�!!!\n");
    else if(prize[7][0]==input[5] && prize[7][1]==input[6] && prize[7][2]==input[7])
        printf("������o'����'2�ʤ�!!!\n");
    else
        printf("'%c%c%c%c%c%c%c%c%'�o�i������\n",input[0],input[1],input[2],input[3],input[4],input[5],input[6],input[7],input[8],input[9]);
}
int main()
{
    int type,i,j;
    char prize[8][9];
    char input[9];
    Start(prize);
    while(1)
    {
        printf("�п�J8��o���Ʀr���X�A��J0�����{�� : ");
        Scan(input, 2);
        Check(prize,input);
    }
}
