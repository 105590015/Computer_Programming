#include<stdio.h>
int Go(int maze[40][40],int start1,int start2,int end1,int end2)
{
    maze[start1][start2]=2;
    if(start1==end1&&start2==end2)
    {
        maze[end1][end2]=2;
        return 1;
    }
    if(maze[start1][start2+1]==0&&maze[end1][end2]!=2)
        Go(maze,start1,start2+1,end1,end2);
    if(maze[start1+1][start2]==0&&maze[end1][end2]!=2)
        Go(maze,start1+1,start2,end1,end2);
    if(maze[start1][start2-1]==0&&maze[end1][end2]!=2)
        Go(maze,start1,start2-1,end1,end2);
    if(maze[start1-1][start2]==0&&maze[end1][end2]!=2)
        Go(maze,start1-1,start2,end1,end2);
    if(maze[end1][end2]!=2)
        maze[start1][start2]=0;
    return maze[end1][end2]/2;
}
main()
{
    int n,maze[40][40],i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&maze[i][j]);
    if(Go(maze,1,1,n-2,n-2)==1)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(maze[i][j]==2)
                    printf("# ");
                else
                    printf("%d ",maze[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("no way\n");
}
