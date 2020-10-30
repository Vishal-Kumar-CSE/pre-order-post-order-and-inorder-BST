#include<stdio.h>
struct node* newnode(int);

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
int main()
{
    int n;
    struct node* root = newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->right->right=newnode(5);
    printf("***************** BST Orders*******************");
    main : printf("\n1:preorder\n2:inorder\n3:postorder\nEnter your choice:\t");
    scanf("%d", &n);
    switch(n)
    {
    case 1:preorder(root);
    goto main;
    break;
    case 2: inorder(root);
    goto main;
    break;
    case 3: postorder(root);
    goto main;
    break;
    default:
        printf("\nWrong Input try again!!");{
        exit(0);}
    }
    return 0;
}
struct node* newnode(int data)
{
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return(node);
}

void postorder(struct node* node)
{
   if(node==NULL)
    return;
   postorder(node->left);
   postorder(node->right);
   printf("%d", node->data);
}

void preorder(struct node* node)
{
   if(node==NULL)
    return;
    printf("%d", node->data);
     preorder(node->left);
   preorder(node->right);

}
void inorder(struct node* node)
{
   if(node==NULL)
    return;
     inorder(node->left);
    printf("%d", node->data);
   inorder(node->right);

}







