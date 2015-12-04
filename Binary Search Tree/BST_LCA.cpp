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

struct node * temp=new node;
temp->data=e;
temp->left=NULL;
temp->right=NULL;
struct node * ret=root;
struct node * last;
if(root)
    {

    while(root)
    {
        last=root;
        if(root->data==e)
            {
                printf("already present");
            }
        else if(root->data<e)
            {

            root=root->right;

            }
        else
            {

            root=root->left;
            }
    }
    if(last->data<e)
       {
         last->right=temp;

       }
       else
       {
        last->left=temp;

       }

        return ret;
}
else
    {
        return temp;


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

int LCA(struct node * root,int v1,int v2)
{
    if(root)
    {   int v;
        if(v1<=root->data&&v2>=root->data||v2<=root->data&&v1>=root->data)
            return root->data;
        if(v=LCA(root->left,v1,v2))
            return v;
        if(v=LCA(root->right,v1,v2))
        return v;
    }
    return 0;
}




int main()
{
struct node * root=NULL;

root=BST_insert(root,8);

root=BST_insert(root,11);
root=BST_insert(root,2);

root=BST_insert(root,1);

root=BST_insert(root,4);
root=BST_insert(root,3);


inorder(root);
printf("%d ",LCA(root,11,2));
}
