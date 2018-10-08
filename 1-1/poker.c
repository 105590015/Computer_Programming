#include<stdio.h>
void judge(int *data, int *r)
{
    int A[5];
    int B[5];
    int i,j,k,l,m,n=0,o=0,p=1,sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0,temp;
    for(i=0;i<5;i++)
    {
        A[i]=*(data+i)%10;
        B[i]=*(data+i)/10;
    }
    for(j=0;j<5;j++)
    {
        for(k=j;k<5;k++)
        {
            if(B[k]<B[j])
            {
                temp=B[k];
                B[k]=B[j];
                B[j]=temp;
            }
        }
    }
    /*printf("%d,%d,%d,%d,%d\n%d,%d,%d,%d,%d\n",A[0],A[1],A[2],A[3],A[4],B[0],B[1],B[2],B[3],B[4]);*/
    for(l=0;l<4;l++)
    {
        if(A[l]==A[l+1])
            sum1++;
        if(B[l]==B[l+1]-1)
            sum2++;
        if(B[l]==B[l+1])
            sum5++;
    }
    if((B[4]==13)&&(B[0]==1))
        sum2++;
    while(B[n]==B[n+1])
        {
            sum3++;
            n++;
        }
    while(B[4]==B[4-o-1])
        {
            sum4++;
            o++;
        }
    while(B[p]==B[p+1])
        {
            sum6++;
            p++;
        }
    if((sum1==4)&&(sum2==4))
        *r=7;
    else if(sum2==4)
        *r=6;
    else if(((sum3==3)&&(sum4==0))||((sum3==0)&&(sum4==3)))
        *r=5;
    else if(((sum3==2)&&(sum4==1))||((sum3==1)&&(sum4==2)))
        *r=4;
    else if((sum3==2)||(sum4==2)||(sum6==2))
        *r=3;
    else if(sum5==2)
        *r=2;
    else if(sum5==1)
        *r=1;
    else
        *r=0;
}
main()
{
    int data[5];
    int r;
    scanf("%d%d%d%d%d",&data[0],&data[1],&data[2],&data[3],&data[4]);
    judge(data,&r);
    printf("%d",r);
}
