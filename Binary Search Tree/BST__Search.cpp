#include<stdio.h>
#include<iostream>

struct node
{
int data;
node * left;
node * right;


};

int find(struct node * root,int ele)
{

if(root)
{
if(root->data==ele)
        return 1;
else if(root->data<ele)
    return find(root->right,ele);
else
    return find(root->left,ele);

}
return 0;
}


int find_non_recursive(struct node * root,int ele)
{
      while(root)
    {
        if(root->data==ele)
        return 1;
        else if(root->data<ele)
            root->right;
        else
            root=root->left;



    }
    return 0;


}

int main()
{

}
