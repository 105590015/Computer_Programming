#include<stdio.h>
#include<stdlib.h>
typedef struct func_s
{
    int number;
    int pow;
    struct func_s *next;
}func_t;

func_t *MakeFunc()
{
    func_t *f2=(func_t*)malloc(sizeof(func_t));
    int n;
    char c;
    scanf("%d%c",&n,&c);
    f2->number=n;
    if(c!='\n')
    {
        f2->next=MakeFunc();
        f2->pow=(*(f2->next)).pow+1;
    }
    else
    {
        f2->next=NULL;
        f2->pow=0;
    }
    return f2;
}
void Input(func_t *f)
{
    int n;
    char c;
    scanf("%d%c",&n,&c);
    f->number=n;
    if(c!='\n')
    {
        f->next=MakeFunc();
        f->pow=(*(f->next)).pow+1;
    }
    else
    {
        f->next=NULL;
        f->pow=0;
    }
}
void Add(func_t *f1,func_t *f2)
{
    func_t *f11,*f22;
    while(f1->next!=NULL)
    {
        if(f1->pow==f2->pow)
        {
            printf("%d ",f1->number+f2->number);
            f11=f1;
            f1=f1->next;
            f22=f2;
            f2=f2->next;
            free(f11);
            free(f22);
        }
        else
        {
            printf("%d ",f1->number);
            f11=f1;
            f1=f1->next;
            free(f11);
        }
    }
    printf("%d",f1->number+f2->number);
}
main()
{
    func_t f1,f2,temp;
    Input(&f1);
    Input(&f2);
    if(f1.pow < f2.pow)
    {
        temp.number=f1.number;
        temp.pow=f1.pow;
        temp.next=f1.next;
        f1.number=f2.number;
        f1.pow=f2.pow;
        f1.next=f2.next;
        f2.number=temp.number;
        f2.pow=temp.pow;
        f2.next=temp.next;
    }
    Add(&f1,&f2);
}
