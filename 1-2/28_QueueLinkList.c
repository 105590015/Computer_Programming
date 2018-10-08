#include<stdio.h>
#include<string.h>
typedef struct node_s
{
    int data;
    struct node_s *next;
}node_t;
typedef struct queue_s
{
    char name[10];
    int size;
    struct node_s *queue;
}queue_t;
node_t *MakeNode(int d)
{
    node_t *newnode=(node_t*)malloc(sizeof(node_t));
    newnode->data=d;
    newnode->next=NULL;
    return newnode;
}
void CreateQueue(queue_t *q)
{
    char nam[10];
    scanf("%[^\n]",nam);
    strcpy(q->name,nam);
    q->size=0;
    q->queue=NULL;
}
void EnQueue(queue_t q[],int qn)
{
    node_t *current;
    int i,data,jud=0;
    char nam[10];
    scanf("%[^\n] %d",nam,&data);
    for(i=0;i<qn;i++)
    {
        if(strcmp(q[i].name,nam)==0)
        {
            jud=1;
            current=q[i].queue;
            if(q[i].queue==NULL)
            {
                q[i].queue=MakeNode(data);
                q[i].size++;
            }
            else
            {
                while(current->next!=NULL)
                    current=current->next;
                current->next=MakeNode(data);
                q[i].size++;
            }
        }
    }
    if(jud==0)
        printf("Queue %s isn't exist\n",nam);
}
void DeQueue(queue_t q[],int qn)
{
    node_t *current;
    int i,jud=0;
    char nam[10];
    scanf("%[^\n]",nam);
    for(i=0;i<qn;i++)
    {
        if(strcmp(q[i].name,nam)==0)
        {
            jud=1;
            current=q[i].queue;
            if(q[i].queue==NULL)
                printf("Queue is empty\n");
            else
            {
                q[i].queue=q[i].queue->next;
                q[i].size--;
                free(current);
            }
        }
    }
    if(jud==0)
        printf("Queue %s isn't exist\n",nam);
}
void MergeQueue(queue_t q[],int *qn)
{
    node_t *current;
    int i,j,jud1=0,jud2=0;
    char nam1[10],nam2[10],enter;
    scanf("%[^\n]%c%[^\n]",nam1,&enter,nam2);
    for(i=0;i<*qn;i++)
    {
        if(strcmp(q[i].name,nam1)==0)
            jud1=1;
        for(j=0;j<*qn;j++)
        {
            if(strcmp(q[j].name,nam2)==0)
                jud2=1;
            if(strcmp(q[i].name,nam1)==0&&strcmp(q[j].name,nam2)==0)
            {

                current=q[i].queue;
                if(q[i].queue==NULL)
                {
                    q[i].queue=q[j].queue;
                    q[i].size+=q[j].size;
                }
                else
                {
                    while(current->next!=NULL)
                        current=current->next;
                    current->next=q[j].queue;
                    q[i].size+=q[j].size;
                }
                q[j].size=-1;
                *qn--;
            }
        }
    }
    if(jud1==0)
        printf("Queue %s isn't exist\n",nam1);
    if(jud2==0)
        printf("Queue %s isn't exist\n",nam2);
}
void PrintAllQueue(queue_t q[],int qn)
{
    node_t *current;
    int i;
    printf("****************************************\n");
    if(qn==0)
        printf("Isn't have any queue\n");
    else
    {
        for(i=0;i<qn;i++)
        {
            if(q[i].queue==NULL)
                printf("Queue Name:%s Queue Size:%d Queue Element:Queue is empty\n",q[i].name,q[i].size);
            else if(q[i].size!=-1)
            {
                printf("Queue Name:%s Queue Size:%d Queue Element:",q[i].name,q[i].size);
                current=q[i].queue;
                while(current->next!=NULL)
                {
                    printf("%d ",current->data);
                    current=current->next;
                }
                printf("%d\n",current->data);
            }
        }
    }
    printf("****************************************\n");
}
int main()
{
    queue_t q[10];
    int n=0,qn=0;
    char enter;
    while(n!=6)
    {
        scanf("%d%c",&n,&enter);
        if(n==1)
            CreateQueue(&q[qn++]);
        else if(n==2)
            EnQueue(q,qn);
        else if(n==3)
            DeQueue(q,qn);
        else if(n==4)
            MergeQueue(q,&qn);
        else if(n==5)
            PrintAllQueue(q,qn);
    }
}
