#include<stdio.h>
int Compute(int family[20][20],int l,int u,int n)
{
    int i,j,k;
    for(i=1;i<n;i++)
    {
        if(family[l][i]==u||family[u][i]==l)
            return i;
    }
    for(j=1;j<n;j++)
    {
        for(k=1;k<n;k++)
        {
            if(family[l][j]==family[u][k])
                return j+k;
        }
    }
}
void MakeArray(int family[20][20],int o,int y)
{
    int i,j,k;
    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
        {
            if(family[i][j]==y)
            {
                family[i][j+1]=o;
                for(k=1;k<20;k++)
                {
                    if(family[o][k]!=-1)
                        family[i][j+1+k]=family[o][k];
                }
            }
        }
    }
}
main()
{
    int family[20][20],n,i,j,k,l,u,old,young;
    scanf("%d",&n);
    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
        {
            family[i][j]=-1;
        }
        family[i][0]=i;
    }
    for(k=1;k<n;k++)
    {
        scanf("%d%d",&old,&young);
        MakeArray(family,old,young);
    }
    for(l=0;l<n;l++)
    {
        for(u=l+1;u<n;u++)
            printf("%d-%d-%d\n",l,u,Compute(family,l,u,n));
    }
}
