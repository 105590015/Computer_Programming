#include<stdio.h>
int BubbleSort(int num2[],int t,int end)
{
    int num[20]={0},i,j,k,l,temp,sum=0;
    for(l=0;l<20;l++)
        num[l]=num2[l];
    for(i=0;i<end;i++)
    {
        for(j=i;j<end;j++)
        {
            if(t==0)
            {
                if(num[i]>num[j])
                {
                    temp=num[i];
                    num[i]=num[j];
                    num[j]=temp;
                    sum++;
                }
            }
            else if(t==1)
            {
                if(num[i]<num[j])
                {
                    temp=num[i];
                    num[i]=num[j];
                    num[j]=temp;
                    sum++;
                }
            }
        }
    }
    for(k=0;k<i;k++)
        printf("%d ",num[k]);
    printf("\n");
    return sum;
}
int InsertionSort(int num2[],int t,int end)
{
    int num[20]={0},i,j,l,temp,sum=0;
    for(l=0;l<20;l++)
        num[l]=num2[l];
  	for(i=1;i<end;i++)
    {
  		temp=num[i];
  		j=i-1;
  		if(t==0)
        {
            while(j>=0&&num[j]>temp)
  		    {
  			    num[j+1]=num[j];
  			    sum++;
                j--;
  		    }
        }
  		else if(t==1)
        {
            while(j>=0&&num[j]<temp)
  		    {
  			    num[j+1]=num[j];
  			    sum++;
                j--;
  		    }
        }
 		num[j+1]=temp;
 	}
 	return sum;
}
int SelectionSort(int num2[],int t,int end)
{
    int num[20]={0},i,j,l,sum=0,min=999,max=0,temp,u=0;
    for(l=0;l<20;l++)
        num[l]=num2[l];
    for(i=0;i<end;i++)
    {
        min=999;
        max=0;
        if(t==0)
        {
            for(j=i+1;j<end;j++)
            {
                if(num[j]<min)
                {
                    min=num[j];
                    u=j;
                }
            }
            if(min<num[i])
            {
                temp=num[i];
                num[i]=min;
                num[u]=temp;
                sum++;
            }
        }
        else if(t==1)
        {
            for(j=i+1;j<end;j++)
            {
                if(num[j]>max)
                {
                    max=num[j];
                    u=j;
                }
            }
            if(max>num[i])
            {
                temp=num[i];
                num[i]=max;
                num[u]=temp;
                sum++;
            }
        }
    }
    return sum;
}
main()
{
    int num[20]={0},t,i=0;
    scanf("%d",&num[0]);
    while(num[i]!=(-999))
    {
        i++;
        scanf("%d",&num[i]);
    }
    scanf("%d",&t);
    printf("Bubble Sort change times = %d\n",BubbleSort(num,t,i));
    printf("Insertion Sort change times = %d\n",InsertionSort(num,t,i));
    printf("Selection Sort change times = %d\n",SelectionSort(num,t,i));
}
