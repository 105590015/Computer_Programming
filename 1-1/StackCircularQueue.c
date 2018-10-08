#include<stdio.h>
main()
{
    int s[5]={0},type,m,n,i=0,j,front=0,rear=0;
    scanf("%d",&type);
    if(type==1)
    {
        while(1)
        {
            scanf("%d",&m);
            if(i>=0&&i<=5)
            {
                if(m==1)
                {
                    scanf("%d",&n);
                    s[i]=n;
                    i++;
                }
                else if(m==2)
                {
                    s[i-1]=0;
                    i--;
                }
                else if(m==3)
                {
                    for(j=0;j<=i-1;j++)
                        printf("%d ",s[j]);
                    break;
                }
                if(i<0)
                {
                    printf("EMPTY");
                    break;
                }
                if(i>5)
                {
                    printf("FULL");
                    break;
                }
            }
        }
    }
    else if(type==2)
    {
        while(1)
        {
            scanf("%d",&m);
            if((rear+1)%5==front&&m==1)
            {
                printf("FULL");
                break;
            }
            if(front==rear&&m==2)
            {
                printf("EMPTY");
                break;
            }
            if(m==1)
            {
                rear++;
                rear=rear%5;
                scanf("%d",&n);
                s[rear]=n;
                i++;
            }
            else if(m==2)
            {
                front++;
                front=front%5;
                s[front]=0;
                i--;
            }
            else if(m==3)
            {
                for(j=1;j<=i;j++)
                    printf("%d ",s[(front+j)%5]);
                break;
            }
        }
    }
}
