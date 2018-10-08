#include<stdio.h>
typedef struct node_s{
    int data;
    struct node_s *left;
    struct node_s *right;
}node_t;
typedef struct node_sp{
    node_t *root;
}node_tp;
void Inorder(node_t *node)
{
    if(node==NULL)
        printf("null");
    else
    {
        if(node->left!=NULL)
            Inorder(node->left);
        printf("%d ",node->data);
        if(node->right!=NULL)
            Inorder(node->right);
    }
}
void Insert(node_tp *node,int key)
{
    node_t *old,*current=node->root,*newnode=(node_t *)malloc(sizeof(node_t));
    int n;
    newnode->data=key;
    newnode->left=NULL;
    newnode->right=NULL;
    if(node->root==NULL)
        node->root=newnode;
    else
    {
        while(current!=NULL)
        {
            if(current->data>=key)
            {
                old=current;
                n=1;
                current=current->left;
            }
            else if(current->data<key)
            {
                old=current;
                n=2;
                current=current->right;
            }
        }
        if(n==1)
            old->left=newnode;
        else if(n==2)
            old->right=newnode;
    }
}
int main(void)
{
    node_tp node={NULL};
    int key;
    char n;
    scanf("%c",&n);
    while(n!='e')
    {
        if(n=='p')
        {
            Inorder(node.root);
            printf("\n");
        }
        else if(n=='i')
        {
            scanf("%d",&key);
            Insert(&node,key);
        }
        scanf("%c",&n);
    }
}
