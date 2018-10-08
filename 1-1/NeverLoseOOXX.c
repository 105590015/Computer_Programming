#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}
void drawPicture(int *area)
{ /*µe¤«¹Ï®× */
    int i,j;
    for(i=0;i<3;i++)
    {
        for (j=0; j<2; j++)
        {
            gotoxy(2*j+1,2*i);
            printf("%c",'|');
        }
        gotoxy(0,2*i+1);
        for (j=0; j<=6; j++)
            printf("%c",'-');
        for (j=0; j<3; j++)
        {
            gotoxy(2*i, 2*j);
            if (*(area+j*3+i)==1)
                printf("O");
            else if (*(area+j*3+i)==-1)
                printf("X");
        }
    }
    printf("\n\n");
}
int row(int *area,int i,int f)
{
    int j,com=0,per=0;
    for(j=0;j<3;j++)
    {
        if(*(area+i*3+j)==1)
            com++;
        else if(*(area+i*3+j)==-1)
            per--;
    }
    //printf("%d,%d\n",com,per);
    if(f==1) return com;
    else     return per;
}
int column(int *area,int j,int f)
{
    int i,com=0,per=0;
    for(i=0;i<3;i++)
    {
        if(*(area+i*3+j)==1)
            com++;
        else if(*(area+i*3+j)==-1)
            per--;
    }
    //printf("%d,%d\n",com,per);
    if(f==1) return com;
    else     return per;
}
int slash(int *area,int i,int j,int f)
{
    int k,l,com=0,per=0;
    if((i==0&&j==0)||(i==1&&j==1)||(i==2&&j==2))
    {
        for(k=0;k<3;k++)
        {
            if(*(area+k*3+k)==1)
                com++;
            else if(*(area+k*3+k)==-1)
                per--;
        }
    }
    else if((i==0&&j==2)||(i==1&&j==1)||(i==2&&j==0))
    {
        for(k=0;k<3;k++)
        {
            if(*(area+k*3+2-k)==1)
                com++;
            else if(*(area+k*3+2-k)==-1)
                per--;
        }
    }
    //printf("%d,%d\n",com,per);
    if(f==1) return com;
    else     return per;
}
int win(int *area,char *w)
{
    int i,j,r=0,c=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(*(area+i*3+j)==1)
                r++;
            else if(*(area+i*3+j)==-1)
                r--;
        }
        if(r==3)
        {
            *w='c';
            return 1;
        }
        else if(r==-3)
        {
            *w='p';
            return 1;
        }
        r=0;
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(*(area+j*3+i)==1)
                c++;
            else if(*(area+j*3+i)==-1)
                c--;
        }
        if(c==3)
        {
            *w='c';
            return 1;
        }
        else if(c==-3)
        {
            *w='p';
            return 1;
        }
        c=0;
    }
    if((*(area)==1&&*(area+4)==1&&*(area+8)==1)||(*(area+2)==1&&*(area+4)==1&&*(area+6)==1))
    {
        *w='c';
        return 1;
    }
    else if((*(area)==-1&&*(area+4)==-1&&*(area+8)==-1)||(*(area+2)==-1&&*(area+4)==-1&&*(area+6)==-1))
    {
        *w='p';
        return 1;
    }
    return 0;
}
int computerwillwin(int *area,int *x,int *y)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(*(area+i*3+j)==0&&(row(area,i,1)==2||column(area,j,1)==2||slash(area,i,j,1)==2))
            {
                printf("Computer will win with (%d, %d)\n",i,j);
                *x=i; *y=j;
                return 1;
            }
        }
    }
    return 0;
}
int playerwillwin(int *area,int *x,int *y)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(*(area+i*3+j)==0&&(row(area,i,-1)==-2||column(area,j,-1)==-2||slash(area,i,j,-1)==-2))
            {
                printf("Player will win with (%d, %d)\n",i,j);
                *x=i; *y=j;
                return -1;
            }
        }
    }
    return 0;
}
void ai(int *area,int *s)
{
    int i,j,x,y;
    if(*s==0&&*area==0)
    {
        *area=1;
        *s++;
    }
    else if(*s==0&&*area==-1)
    {
        *(area+2)=1;
        *s+=2;
    }
    else if(*s==1&&*(area+1)!=-1&&*(area+2)==0)
    {
        *(area+2)=1;
        *s+=2;
    }
    else if(*s==1&&*(area+3)!=-1&&*(area+6)==0)
    {
        *(area+6)=1;
        *s+=2;
    }
    else if(*s==2&&*(area+5)!=-1&&*(area+8)==0)
    {
        *(area+8)=1;
        *s+=2;
    }
    else
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(*(area+i*3+j)==0)
                {
                    x=i;y=j;
                }
            }
        }
        *(area+3*x+y)=1;
    }
}
main()
{
    int area[3][3]={0},x,y,j,k,x1,y1,s=0,end=0;
    char w;
    area[1][1]=1;
    drawPicture(area);
    while(win(area,&w)!=1)
    {
        scanf("%d",&x);
        scanf("%d",&y);
        if(area[x][y]!=0)
            printf("input error\n");
        else
        {
            area[x][y]=-1;
            if((computerwillwin(area,&x1,&y1)==1||playerwillwin(area,&x1,&y1)==-1)&&(area[x1][y1]==0))
                area[x1][y1]=1;
            else
            {
                ai(area,&s);
                printf("%d\n",s);
            }
        }
        drawPicture(area);
        if(area[0][0]!=0&&area[0][1]!=0&&area[0][2]!=0&&area[1][0]!=0&&area[1][1]!=0&&area[1][2]!=0&&area[2][0]!=0&&area[2][1]!=0&&area[2][2]!=0)
        {
            printf("gggggggg\n");
            break;
        }
    }
    if(w=='c')       printf("Computer win");
    else if(w=='p')  printf("Player win");
}
