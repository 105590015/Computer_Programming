#include<stdio.h>
typedef struct node_s
{
    char data;
    struct node_s *left;
    struct node_s *right;
}node_t;
typedef struct node_sp
{
    node_t *root;
}node_tp;
int Input(char i[20])
{
    int n=0;
    char c='0';
    scanf("%c",&c);
    while(c!='\n')
    {
        i[n++]=c;
        scanf("%c",&c);
    }
    return n;
}
node_t* Type1(char *i1,char *i2,int n)
{
    int t;
    node_t *newnode=(node_t *)malloc(sizeof(node_t));
    newnode->data=*i1;
    newnode->left=NULL;
    newnode->right=NULL;
    for(t=0;(*i1)!=(*(i2+t));t++)
    if(n==1)
        return newnode;
    if(t>0)
        newnode->left=Type1(i1+1,i2,t);
    if(n-t-1>0)
        newnode->right=Type1(i1+t+1,i2+t+1,n-t-1);
    return newnode;
}
node_t* Type2(char *i1,char *i2,int n)
{
    int t=0;
    node_t *newnode=(node_t *)malloc(sizeof(node_t));
    newnode->data=*(i1+n-1);
    newnode->left=NULL;
    newnode->right=NULL;
    for(t=0;(*(i1+n-1))!=(*(i2+t));t++)
    if(n==1)
        return newnode;
    if(t>0)
        newnode->left=Type2(i1,i2,t);
    if(n-t-1>0)
        newnode->right=Type2(i1+t,i2+t+1,n-t-1);
    return newnode;
}
int height(node_t *node)
{
    if(node==NULL)
        return 0;
    else
    {
        int lheight=height(node->left);
        int rheight=height(node->right);
        if (lheight>rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
void printGivenLevel(node_t *root,int level)
{
    if(root==NULL)
        return;
    if(level==1)
        printf("%c",root->data);
    else if(level>1)
    {
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
}
void Print(node_t *root)
{
    int h=height(root);
    int i;
    for (i=1;i<=h;i++)
        printGivenLevel(root,i);
}
int main(void)
{
    node_tp node;
    int n;
    char t1,t2,enter,i1[20]={'\n'},i2[20]={'\n'};
    scanf("%c%c",&t1,&enter);
    n=Input(i1);
    scanf("%c%c",&t2,&enter);
    n=Input(i2);
    if(t1=='P'&&t2=='I')
        node.root=Type1(i1,i2,n);
    else if(t1=='I'&&t2=='P')
        node.root=Type1(i2,i1,n);
    else if(t1=='O'&&t2=='I')
        node.root=Type2(i1,i2,n);
    else if(t1=='I'&&t2=='O')
        node.root=Type2(i2,i1,n);
    Print(node.root);
}
