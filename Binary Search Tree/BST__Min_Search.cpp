#include<stdio.h>
#include<iostream>

struct node
{
int data;
node * left;
node * right;


};

int findmin(struct node * root)
{

if(root)
{
if(root->left==NULL)
    return root;
return find(root->left);
}
return 0;

}


int findmin_non_recursive(struct node * root)
{

while(root)
{
    if(root->left==NULL)
        return root;
    else
        root=root->left;


}
return 0;

}




int main()
{

}
