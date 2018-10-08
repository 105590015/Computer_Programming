#include<stdio.h>
void Print(int b1,int i1,int j1,int b2,int i2, int j2)
{
    if       (b1==101)                                     printf("General(%d,%d)->",i1,j1);
    else if  (b1==102||b1==103)                            printf("Guard(%d,%d)->",i1,j1);
    else if  (b1==104||b1==105)                            printf("Elephant(%d,%d)->",i1,j1);
    else if  (b1==106||b1==107)                            printf("Rook(%d,%d)->",i1,j1);
    else if  (b1==108||b1==109)                            printf("Horse(%d,%d)->",i1,j1);
    else if  (b1==110||b1==111)                            printf("Bom(%d,%d)->",i1,j1);
    else if  (b1==112||b1==113||b1==114||b1==115||b1==116) printf("Pawn(%d,%d)->",i1,j1);
    else if  (b1==201)                                     printf("King(%d,%d)->",i1,j1);
    else if  (b1==202||b1==203)                            printf("Assistant(%d,%d)->",i1,j1);
    else if  (b1==204||b1==205)                            printf("Bishop(%d,%d)->",i1,j1);
    else if  (b1==206||b1==207)                            printf("Chariot(%d,%d)->",i1,j1);
    else if  (b1==208||b1==209)                            printf("Knight(%d,%d)->",i1,j1);
    else if  (b1==210||b1==211)                            printf("Cannon(%d,%d)->",i1,j1);
    else if  (b1==212||b1==213||b1==214||b1==215||b1==216) printf("Soldier(%d,%d)->",i1,j1);
    if       (b2==101)                                     printf("General(%d,%d)\n",i2,j2);
    else if  (b2==102||b2==103)                            printf("Guard(%d,%d)\n",i2,j2);
    else if  (b2==104||b2==105)                            printf("Elephant(%d,%d)\n",i2,j2);
    else if  (b2==106||b2==107)                            printf("Rook(%d,%d)\n",i2,j2);
    else if  (b2==108||b2==109)                            printf("Horse(%d,%d)\n",i2,j2);
    else if  (b2==110||b2==111)                            printf("Bom(%d,%d)\n",i2,j2);
    else if  (b2==112||b2==113||b2==114||b2==115||b2==116) printf("Pawn(%d,%d)\n",i2,j2);
    else if  (b2==201)                                     printf("King(%d,%d)\n",i2,j2);
    else if  (b2==202||b2==203)                            printf("Assistant(%d,%d)\n",i2,j2);
    else if  (b2==204||b2==205)                            printf("Bishop(%d,%d)\n",i2,j2);
    else if  (b2==206||b2==207)                            printf("Chariot(%d,%d)\n",i2,j2);
    else if  (b2==208||b2==209)                            printf("Knight(%d,%d)\n",i2,j2);
    else if  (b2==210||b2==211)                            printf("Cannon(%d,%d)\n",i2,j2);
    else if  (b2==212||b2==213||b2==214||b2==215||b2==216) printf("Soldier(%d,%d)\n",i2,j2);
}
void Bom(int board[3][3],int i,int j)
{
    if(i-2>-1&&board[i-1][j]!=-1&&board[i][j]/100!=board[i-2][j]/100&&board[i-2][j]!=-1&&board[i][j]!=-1)
        Print(board[i][j],i,j,board[i-2][j],i-2,j);
    if(j-2>-1&&board[i][j-1]!=-1&&board[i][j]/100!=board[i][j-2]/100&&board[i][j-2]!=-1&&board[i][j]!=-1)
        Print(board[i][j],i,j,board[i][j-2],i,j-2);
    if(j+2<3&&board[i][j+1]!=-1&&board[i][j]/100!=board[i][j+2]/100&&board[i][j+2]!=-1&&board[i][j]!=-1)
        Print(board[i][j],i,j,board[i][j+2],i,j+2);
    if(i+2<3&&board[i+1][j]!=-1&&board[i][j]/100!=board[i+2][j]/100&&board[i+2][j]!=-1&&board[i][j]!=-1)
        Print(board[i][j],i,j,board[i+2][j],i+2,j);
}
void King(int board[3][3],int i,int j)
{
    if(i-1>-1&&board[i-1][j]%100<12&&board[i][j]/100!=board[i-1][j]/100&&board[i-1][j]!=-1&&board[i][j]!=-1)
        Print(board[i][j],i,j,board[i-1][j],i-1,j);
    if(j-1>-1&&board[i][j-1]%100<12&&board[i][j]/100!=board[i][j-1]/100&&board[i][j-1]!=-1&&board[i][j]!=-1)
        Print(board[i][j],i,j,board[i][j-1],i,j-1);
    if(j+1<3&&board[i][j+1]%100<12&&board[i][j]/100!=board[i][j+1]/100&&board[i][j+1]!=-1&&board[i][j]!=-1)
        Print(board[i][j],i,j,board[i][j+1],i,j+1);
    if(i+1<3&&board[i+1][j]%100<12&&board[i][j]/100!=board[i+1][j]/100&&board[i+1][j]!=-1&&board[i][j]!=-1)
        Print(board[i][j],i,j,board[i+1][j],i+1,j);
}
void Soldier(int board[3][3],int i,int j)
{
    if(i-1>-1&&board[i][j]!=-1&&board[i-1][j]!=-1&&board[i][j]/100!=board[i-1][j]/100&&((board[i-1][j]%100>11&&board[i-1][j]%100<17)||board[i-1][j]%100==1))
        Print(board[i][j],i,j,board[i-1][j],i-1,j);
    if(j-1>-1&&board[i][j]!=-1&&board[i][j-1]!=-1&&board[i][j]/100!=board[i][j-1]/100&&((board[i][j-1]%100>11&&board[i][j-1]%100<17)||board[i][j-1]%100==1))
        Print(board[i][j],i,j,board[i][j-1],i,j-1);
    if(j+1<3&&board[i][j]!=-1&&board[i][j+1]!=-1&&board[i][j]/100!=board[i][j+1]/100&&((board[i][j+1]%100>11&&board[i][j+1]%100<17)||board[i][j+1]%100==1))
        Print(board[i][j],i,j,board[i][j+1],i,j+1);
    if(i+1<3&&board[i][j]!=-1&&board[i+1][j]!=-1&&board[i][j]/100!=board[i+1][j]/100&&((board[i+1][j]%100>11&&board[i+1][j]%100<17)||board[i+1][j]%100==1))
        Print(board[i][j],i,j,board[i+1][j],i+1,j);
}
void Normal(int board[3][3],int i,int j)
{
    if(i-1>-1&&board[i][j]!=-1&&board[i-1][j]!=-1&&board[i-1][j]%100>=board[i][j]%100&&board[i][j]/100!=board[i-1][j]/100)
        Print(board[i][j],i,j,board[i-1][j],i-1,j);
    if(j-1>-1&&board[i][j]!=-1&&board[i][j-1]!=-1&&board[i][j-1]%100>=board[i][j]%100&&board[i][j]/100!=board[i][j-1]/100)
        Print(board[i][j],i,j,board[i][j-1],i,j-1);
    if(j+1<3&&board[i][j]!=-1&&board[i][j+1]!=-1&&board[i][j+1]%100>=board[i][j]%100&&board[i][j]/100!=board[i][j+1]/100)
        Print(board[i][j],i,j,board[i][j+1],i,j+1);
    if(i+1<3&&board[i][j]!=-1&&board[i+1][j]!=-1&&board[i+1][j]%100>=board[i][j]%100&&board[i][j]/100!=board[i+1][j]/100)
        Print(board[i][j],i,j,board[i+1][j],i+1,j);
}
void Judge(int board[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            if(board[i][j]%100==10||board[i][j]%100==11)
                Bom(board,i,j);
            else if(board[i][j]%100==1)
                King(board,i,j);
            else if(board[i][j]%100>11&&board[i][j]%100<17)
                Soldier(board,i,j);
            else
                Normal(board,i,j);
        }
}
main()
{
    int board[3][3]={0},x=0,y=0,z=0;
    while(x!=2||y!=2)
    {
        scanf("%d %d %d",&x,&y,&z);
        board[x][y]=z;
    }
    Judge(board);
}
