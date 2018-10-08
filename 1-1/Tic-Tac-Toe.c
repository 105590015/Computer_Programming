#include<stdio.h>
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
void computerwillwin(int *area)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(*(area+i*3+j)==0&&(row(area,i,1)==2||column(area,j,1)==2||slash(area,i,j,1)==2))
                printf("Computer will win with (%d, %d)\n",i,j);
        }
    }
}
void playerwillwin(int *area)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(*(area+i*3+j)==0&&(row(area,i,-1)==-2||column(area,j,-1)==-2||slash(area,i,j,-1)==-2))
                printf("Player will win with (%d, %d)\n",i,j);
        }
    }
}
main()
{
    int area[3][3]={0},x,y,i,j,k;
    char w,f,type,n;
    scanf("%c",&f);
    if(f=='1')
        i=1;
    else if(f=='0')
        i=-1;
    while(win(area,&w)!=1)
    {
        /*for(j=0;j<3;j++)
        {
            for(k=0;k<3;k++)
            {
                printf("%d ",area[j][k]);
            }
            printf("\n");
        }*/
        scanf("%c",&n);
        scanf("%c",&type);
        if(type=='w')
            computerwillwin(area);
        else if(type=='d')
        {
            computerwillwin(area);
            playerwillwin(area);
        }
        else
        {
            x=type-'0';
            scanf("%d",&y);
            //printf("%d,%d,%d\n",x,y,area[x][y]);
            if(area[x][y]!=0)
                printf("input error\n");
            else
            {
                area[x][y]=i;
                i*=-1;
            }
        }
    }
    if(w=='c')       printf("Computer win");
    else if(w=='p')  printf("Player win");
}
