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
void InputList(node_t *list,int *nullornot)
{
    node_t *newnode=(node_t *)malloc(sizeof(node_t)),*current=list,*temp=list;
    int id,score,time=0;
    char c;
    scanf("%d%c%d%c",&id,&c,&score,&c);
    newnode->data.id=id;
    newnode->data.score=score;
    newnode->next=NULL;
    if(*nullornot==1)
    {
        *nullornot=0;
        list->data.id=id;
        list->data.score=score;
        list->next=NULL;
        printf("Insert data %d:%d, compare:%d.\n",id,score,0);
    }
    else if(list->data.score>score||(list->data.score==score&&list->data.id>id))
    {
        newnode->data.id=list->data.id;
        newnode->data.score=list->data.score;
        newnode->next=list->next;
        list->data.id=id;
        list->data.score=score;
        list->next=newnode;
        printf("Insert data %d:%d, compare:%d.\n",id,score,1);
    }
    else
    {
        while(current!=NULL)
        {
            if(current->data.score<score||(current->data.score==score&&current->data.id<id))
            {
                temp=current;
                current=current->next;
                time++;
            }
            else
            {
                time++;
                break;
            }
        }
        temp->next=newnode;
        newnode->next=current;
        printf("Insert data %d:%d, compare:%d.\n",id,score,time);
    }
}
void DeleteList(node_t *list,int *nullornot)
{
    node_t *current=list,*temp=list;
    int id,jud=0;
    char c;
    scanf("%d%c",&id,&c);
    if(list->data.id==id&&list->next==NULL)
    {
        *nullornot=1;
        printf("Delete student %d successful.\n",id);
        jud=1;
    }
    else if(list->data.id==id)
    {
        list=list->next;
        printf("Delete student %d successful.\n",id);
        jud=1;
    }
    else
    {
        while(current!=NULL)
        {
            if(current->data.id==id)
            {
                temp->next=current->next;
                free(current);
                printf("Delete student %d successful.\n",id);
                jud=1;
            }
            temp=current;
            current=current->next;
        }
    }
    if(jud==0)
        printf("Student %d is not exist.\n",id);
}
main()
{
    node_t list;
    char n='\0',enter;
    int nullornot=1;
    list.next=NULL;
    while(n!='e')
    {
        scanf("%c%c",&n,&enter);
        if(n=='p')
            PrintList(&list,nullornot);
        else if(n=='i')
            InputList(&list,&nullornot);
        else if(n=='d')
            DeleteList(&list,&nullornot);
    }
}
