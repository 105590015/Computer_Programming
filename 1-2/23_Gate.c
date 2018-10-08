#include<stdio.h>
#define GATEVALUE(TYPE) int(*GateValue)(int,int,char)
typedef struct
{
    GATEVALUE();
}Gate;
int P_GateGetValue(int y,int x,char g)
{
    if(g=='N')
        return (x+1)%2;
    else if(g=='E')
        return x;
}
int QR_GateGetValue(int y,int x,char g)
{
    if(g=='A')
    {
        if(y==1&&x==1) return 1;
        else           return 0;
    }
    else if(g=='O')
    {
        if(y==0&&x==0) return 0;
        else           return 1;
    }
}
main()
{
    int x1,x2,x3,y1,y2,y3;
    char c,g1,g2,g3;
    scanf("%d%c%d%c%d",&x1,&c,&x2,&c,&x3);
    scanf(" %c%c%c%c%c",&g1,&c,&g2,&c,&g3);
    Gate p,q,r;
    p.GateValue=P_GateGetValue;
    q.GateValue=QR_GateGetValue;
    r.GateValue=QR_GateGetValue;
    y1=p.GateValue(0,x1,g1);
    y2=q.GateValue(y1,x2,g2);
    y3=r.GateValue(y2,x3,g3);
    printf("%d,%d,%d",y1,y2,y3);
}
