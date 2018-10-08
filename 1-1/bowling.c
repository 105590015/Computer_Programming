#include <stdio.h>
main()
{
    int a=0,b=0,c=0,d=0,e=0,s;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(c==10) scanf("%d",&e);
    s=a+b+c+d+e;
    printf("%d",s);
}
