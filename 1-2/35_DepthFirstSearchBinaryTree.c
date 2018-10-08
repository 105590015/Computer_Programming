#include<stdio.h>
typedef struct node_s{
    char data;
    struct node_s *left;
    struct node_s *mid;
    struct node_s *right;
}node_t;
typedef struct node_sp{
    node_t *root;
}node_tp;
void Sort(char s[])
{
    int i,j;
    char temp;
    for(i=1;i<4,s[i]!='\0';i++)
    {
        for(j=i;j<4,s[j]!='\0';j++)
        {
            if(s[i]>s[j])
            {
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
}
node_t *FindFirst(node_t *node,char first)
{
    if(node->data==first)
        return node;
    else
    {
        if(node->left!=NULL)
        {
            if(FindFirst(node->left,first)->data==first)
                return FindFirst(node->left,first);
        }
        if(node->mid!=NULL)
        {
            if(FindFirst(node->mid,first)->data==first)
                return FindFirst(node->mid,first);
        }
        if(node->right!=NULL)
        {
            if(FindFirst(node->right,first)->data==first)
                return FindFirst(node->right,first);
        }
        return node;
    }
}
void BuildTree(node_tp *node,char first,char c)
{
    node_t *current,*newnode=(node_t *)malloc(sizeof(node_t));
    newnode->data=c;
    newnode->left=NULL;
    newnode->mid=NULL;
    newnode->right=NULL;
    if(node->root==NULL)
        node->root=newnode;
    else
    {
        current=FindFirst(node->root,first);
        if(current->left==NULL)
            current->left=newnode;
        else if(current->left->data>c)
        {
            if(current->mid==NULL)
                current->mid=current->left;
            else
            {
                current->right=current->mid;
                current->mid=current->left;
            }
            current->left=newnode;
        }
        else if(current->mid==NULL)
            current->mid=newnode;
        else if(current->mid->data>c)
        {
            current->right=current->mid;
            current->mid=newnode;
        }
        else if(current->right==NULL)
            current->right=newnode;
    }
}
void DFS(node_t *node)
{
    if(node==NULL)
        printf("null");
    else
    {
        printf("%c",node->data);
        if(node->left!=NULL)
            DFS(node->left);
        if(node->mid!=NULL)
            DFS(node->mid);
        if(node->right!=NULL)
            DFS(node->right);
    }
}
int main(void)
{
    node_tp node={NULL};
    int x=0;
    char n,i[5];
    scanf("%c",&n);
    while(n!='e')
    {
        if(n=='p')
        {
            DFS(node.root);
            printf("\n");
        }
        else if(n=='i')
        {
            scanf("%s",i);
            Sort(i);
            while(i[x]!='\0')
                BuildTree(&node,i[0],i[x++]);
            x=1;
        }
        scanf("%c",&n);
    }
}
