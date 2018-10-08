#include<stdio.h>
int Line(int player1[][3],int player2[][3])
{
    int p1=0,p2=0,i,j,point1=0,point2=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(player1[i][j]==0)
                point1++;
            if(player2[i][j]==0)
                point2++;
        }
        if(point1==3) p1++;
        if(point2==3) p2++;
        point1=0;
        point2=0;
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(player1[j][i]==0)
                point1++;
            if(player2[j][i]==0)
                point2++;
        }
        if(point1==3) p1++;
        if(point2==3) p2++;
        point1=0;
        point2=0;
    }
    if((player1[0][0]==0&&player1[1][1]==0&&player1[2][2]==0)||(player1[0][2]==0&&player1[1][1]==0&&player1[2][0]==0)) p1++;
    if((player2[0][0]==0&&player2[1][1]==0&&player2[2][2]==0)||(player2[0][2]==0&&player2[1][1]==0&&player2[2][0]==0)) p2++;
    if     (p1==p2) return 0;
    else if(p1>p2) return 1;
    else if(p1<p2) return 2;
}
void Win(int player1[][3],int player2[][3],int x1,int x2,int x3)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(player1[i][j]==x1) player1[i][j]=0;
            if(player1[i][j]==x2) player1[i][j]=0;
            if(player1[i][j]==x3) player1[i][j]=0;
            if(player2[i][j]==x1) player2[i][j]=0;
            if(player2[i][j]==x2) player2[i][j]=0;
            if(player2[i][j]==x3) player2[i][j]=0;
        }
    }
    if     (Line(player1,player2)==0) printf("Draw\n");
    else if(Line(player1,player2)==1) printf("Player1 wins\n");
    else if(Line(player1,player2)==2) printf("Player2 wins\n");
}
main()
{
    int player1[3][3]={0},player2[3][3]={0},judge=1,x1,x2,x3,i,j;
    while(judge!=-1)
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                scanf("%d",&player1[i][j]);
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                scanf("%d",&player2[i][j]);
        }
        scanf("%d%d%d%d",&x1,&x2,&x3,&judge);
        Win(player1,player2,x1,x2,x3);
    }
}
