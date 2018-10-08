#include<stdio.h>
void Reduction(int *x1,int *y1)
{
    int i,t;
    t=abs(*x1);
    for(i=t;i>0;i--)
        if( (*x1)%i==0 && (*y1)%i==0 )
        {
            (*x1)/=i;
            (*y1)/=i;
        }
}
void Subtraction(int *x1,int *y1,int x2,int y2,int s1,int s2)
{
    //printf("*x1=%d,*y1=%d,x2=%d,y2=%d,s1=%d,s2=%d\n",*x1,*y1,x2,y2,s1,s2);
    x2*=s1;
    y2*=s2;
    (*x1)=(*x1)*y2-x2*(*y1);
    (*y1)*=y2;
}
main()
{
    int n,i,j,k,l,o,judge,x[50][50]={0},temp[50],s1,s2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n*2;j+=2)
            scanf("%d",&x[i][j]);
        for(j=1;j<=n*2+1;j+=2)
            x[i][j]=1;
    }
    for(k=0;k<n;k++)
    {
        if(x[k][k*2]==0)
        {
        	l=k+1;
        	while(x[l][k*2]==0)
                l++;
           	for(o=0;o<=n*2+1;o++)
            {
	    		temp[o]=x[k][o];
                x[k][o]=x[l][o];
                x[l][o]=temp[o];
	    	}
        }
        for(l=0;l<n;l++)
        {
       	 	if (k!=l)
            {
                s1=x[l][k*2]*x[k][k*2+1];
                s2=x[l][k*2+1]*x[k][k*2];
                for(o=0;o<=n;o++)
                {
                    Subtraction(&x[l][o*2],&x[l][o*2+1],x[k][o*2],x[k][o*2+1],s1,s2);
                    Reduction(&x[l][o*2],&x[l][o*2+1]);
                    if(x[l][o*2]==0) x[l][o*2+1]=1;
                }
            }
        }
        /*for(i=0;i<n;i++)
        {
            for(j=0;j<=20;j++)
                printf("%d ",x[i][j]);
            printf("\n");
        }*/
    }
    for(i=0;i<n;i++)
    {
        x[i][n*2]*=x[i][i*2+1];
        x[i][n*2+1]*=x[i][i*2];
        Reduction(&x[i][n*2],&x[i][n*2+1]);
        if(x[i][n*2]%x[i][n*2+1]==0)
            printf("X[%d] = %d\n",i+1,x[i][n*2]/x[i][n*2+1]);
        else
            printf("X[%d] = %d/%d\n",i+1,x[i][n*2],x[i][n*2+1]);
    }
}
