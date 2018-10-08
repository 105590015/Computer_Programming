#include<stdio.h>
typedef struct node_s
{
    int data;
    struct node_s *next;
}node_t;
typedef struct list_s
{
    struct node_s *top;
}list_t;
void Push(list_t *t)
{
    node_t *newnode;
    int data;
    scanf("%d",&data);
    newnode=(node_t*)malloc(sizeof(node_t));
    newnode->data=data;
    newnode->next=NULL;
    if(t->top==NULL)
        t->top=newnode;
    else
    {
        newnode->next=t->top;
        t->top=newnode;
    }
}
void Pop(list_t *t)
{
    node_t *correct;
    if(t->top!=NULL)
    {
        printf("The data %d is pop\n",t->top->data);
        correct=t->top;
        t->top=t->top->next;
        free(correct);
    }
    else
        printf("The Stack is empty\n");
}
int main()
{
    list_t t={NULL};
    int n=0,data=0;
    while(n!=3)
    {
        scanf("%d",&n);
        if(n==1)
            Push(&t);
        else if(n==2)
            Pop(&t);
    }
    return 0;
}
