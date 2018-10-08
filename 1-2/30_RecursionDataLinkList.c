#include<stdio.h>
typedef struct student_s
{
    int id;
    int score;
}student_t;
typedef struct node_s
{
    student_t data;
    struct node_s *next;
}node_t;
void PrintList(node_t *list,int nullornot)
{

    if(nullornot==1)
        printf("null\n");
    else
    {
        while(list->next!=NULL)
        {
            printf("%d:%d,",list->data.id,list->data.score);
            list=list->next;
        }
        printf("%d:%d\n",list->data.id,list->data.score);
    }
}
void DeleteList(node_t *list,int *nullornot)
{
    node_t *current=list,*temp=list;
    int score,jud=0;
    char c;
    scanf("%d%c",&score,&c);
    if(list==NULL)
        printf("No student greater or equal to score:%d.\n",score);
    if(list->data.score>=score)
        *nullornot=1;
    while(current!=NULL)
    {
        if(current->data.score>=score)
        {
            temp->next=current->next;
            printf("Delete student %d:%d successful.\n",current->data.id,current->data.score);
            free(current);
            current=temp->next;
            jud=1;
        }
        else
        {
            temp=current;
            current=current->next;
        }
    }
    if(jud==0)
        printf("No student greater or equal to score:%d.\n",score);
}
node_t *InputList(node_t *list,int id,int score,int *nullornot,int *time,int *recursion)
{
    *recursion+=1;
    node_t *newnode=(node_t*)malloc(sizeof(node_t));
    newnode->data.id=id;
    newnode->data.score=score;
    newnode->next=NULL;
    if(*nullornot==1)
    {
        *nullornot=0;
        newnode->next=NULL;
        printf("Insert data %d:%d, Compare:%d, Recursive:%d.\n",id,score,*time,*recursion);
        return newnode;
    }
    else if(score<list->data.score||(score==list->data.score&&id<list->data.id))
    {
        *time+=1;
        *recursion+=1;
        newnode->next=list;
        printf("Insert data %d:%d, Compare:%d, Recursive:%d.\n",id,score,*time,*recursion);
        return newnode;
    }
    else if(score>list->data.score||(score==list->data.score&&id>list->data.id))
    {
        *time+=1;
        if(list->next==NULL)
        {
            *recursion+=1;
            list->next=newnode;
            printf("Insert data %d:%d, Compare:%d, Recursive:%d.\n",id,score,*time,*recursion);
            return list;
        }
        else
        {
            free(newnode);
            list->next=InputList(list->next,id,score,nullornot,time,recursion);
            return list;
        }
    }
}
main()
{
    node_t list;
    char n='\0',enter;
    int id,score,nullornot=1,time=0,recursion=0;
    list.data.id=-1;
    list.data.score=-1;
    list.next=NULL;
    while(n!='e')
    {
        scanf("%c%c",&n,&enter);
        if(n=='p')
            PrintList(list.next,nullornot);
        else if(n=='i')
        {
            scanf("%d%c%d%c",&id,&enter,&score,&enter);
            list.next=InputList(list.next,id,score,&nullornot,&time,&recursion);
            recursion=0;
            time=0;
        }
        else if(n=='d')
            DeleteList(list.next,&nullornot);
    }
}

