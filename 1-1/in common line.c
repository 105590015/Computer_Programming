#include <stdio.h>
main()
{
    int a,b,c,d,e,f,t,aa,bb,cc;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    bb=(b-a)+(d-c)+(f-e);
    if(a>b) {t=a;a=b;b=t;}
    if(b>c) {t=b;b=c;c=t;}
    if(a>b) {t=a;a=b;b=t;}
    if(c>d) {t=c;c=d;d=t;}
    if(b>c) {t=b;b=c;c=t;}
    if(a>b) {t=a;a=b;b=t;}
    if(d>e) {t=d;d=e;e=t;}
    if(c>d) {t=c;c=d;d=t;}
    if(b>c) {t=b;b=c;c=t;}
    if(a>b) {t=a;a=b;b=t;}
    if(e>f) {t=e;e=f;f=t;}
    if(d>e) {t=d;d=e;e=t;}
    if(c>d) {t=c;c=d;d=t;}
    if(b>c) {t=b;b=c;c=t;}
    if(a>b) {t=a;a=b;b=t;}
    aa=f-a;
    if(aa>bb) printf("%d",bb);
    else{printf("%d",aa);}
}
