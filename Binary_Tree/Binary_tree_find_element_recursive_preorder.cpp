#include <iostream>       // std::cout
#include <stack>
#include<stdio.h>
#include<queue>
#include<limits.h>
using namespace std;

struct node {
int data;
struct node * left_child;
struct node * right_child;

};
 struct node * constructBT(int pos,int * arr,int size)
 {  if(pos<size)
     {if(arr[pos]!='-1')
     {
         struct node * temp=new node;
         temp->data=arr[pos];
         temp->left_child=constructBT(2*pos+1,arr,size);
         temp->right_child=constructBT(2*pos+2,arr,size);

         return temp;
     }
     else
     {
     return NULL;

     }
     }

     else
      {
          return NULL;

     }


 }

int finder(node * root,char d)
{


if(!root->left_child||!root->right_child)
{
struct node * news=new node;
news->right_child=NULL;
news->left_child=NULL;
news->data=d;
if(!root->left_child)
root->left_child=news;
else
root->right_child=news;
return 1;

}


if(finder(root->left_child,d))
    return 1;
else if(finder(root->right_child,d))
    return 1;
return 0;

}



 void preorder(struct node * root)
 {
    if(root!=NULL)
    {
     printf("%c \n",root->data);
     preorder(root->left_child);
     preorder(root->right_child);

    }


 }






 int main()
 {
 int a[13]={'1','2','3','-1','4','-1','5','6','7','8','-1','9','10'};
struct node * root=constructBT(0,a,13);

finder(root,'f');
preorder(root);
return 0;

 }

