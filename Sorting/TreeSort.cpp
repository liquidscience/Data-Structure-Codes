#include<iostream>
using namespace std;
struct node
{
    struct node * left;
    struct node * right;
    int data;
};
struct node *  insert(struct node * root,int d)
{
    if(root==NULL)
    {   root=new node;
        root->data=d;
        root->left=NULL;
        root->right=NULL;
        return root;

    }
    else if(root->data<d)
         root->right=insert(root->right,d);
    else
        root->left=insert(root->left,d);


    return root;



}

void inorder(struct node * root)
{
    if(root!=NULL)
    {   inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

}



int main()
{

struct node * root=NULL;
root=insert(root,6);
root=insert(root,3);
root=insert(root,1);
root=insert(root,7);
root=insert(root,4);
root=insert(root,2);

inorder(root);

}
