#include<stdio.h>
void compute(int x1, int y1, int x2, int y2, int *perimeter, int *area)
{
    *area=abs(x1-x2)*abs(y1-y2);
    *perimeter=2*abs(x1-x2)+2*abs(y1-y2);
}

int main()
{
    int x1,y1,x2,y2;
    int p=0,a=0;
    int ans1=0,ans2=0;
    while(1)
    {
        scanf("%d",&x1);
        if(x1==-1)
        {
            break;
        }
        scanf("%d%d%d",&y1,&x2,&y2);
        compute(x1,y1,x2,y2,&p,&a);
        if(p>ans1)
        {
            ans1=p;
        }
        if(a>ans2)
        {
            ans2=a;
        }
    }
    printf("%d\n%d",ans2,ans1);
}
