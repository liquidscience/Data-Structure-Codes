#include<iostream>
#include<stdio.h>


struct node
{
int data;
struct node * left;
struct node * right;
};

struct node * BST_insert(struct node * root,int e)
{
if(!root)
{
    struct node * temp=new node;
    temp->data=e;
    temp->left= NULL;
    temp->right=NULL;
    return temp;
}
else
{
    if(root->data<e)
      root->right= BST_insert(root->right,e);
    else
        root->left=BST_insert(root->left,e);

    return root;
}

}
void inorder(struct node * root)
{   if(root)
     {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
     }
}


int main()
{
struct node * root=NULL;

root=BST_insert(root,8);

root=BST_insert(root,7);
root=BST_insert(root,2);

root=BST_insert(root,1);

root=BST_insert(root,4);
root=BST_insert(root,3);


inorder(root);

}
