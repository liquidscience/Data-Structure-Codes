#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node * left_child;
struct node * right_child;

};
 struct node * constructBT(int pos,int * arr,int size)
 {  if(pos<size)
     {if(arr[pos]!='-1')
     {
         struct node * temp=(struct node *)malloc(sizeof(struct node));
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


 void preorder(struct node * root)
 {
    if(root!=NULL)
    {
     printf("%c \n",root->data);
     preorder(root->left_child);
     preorder(root->right_child);

    }


 }

 void postorder(struct node * root)
 {
    if(root!=NULL)
    {

     postorder(root->left_child);
     postorder(root->right_child);
     printf("%c \n",root->data);
    }


 }



  void inorder(struct node * root)
 {
    if(root!=NULL)
    {

     inorder(root->left_child);
       printf("%c \n",root->data);
    inorder(root->right_child);

    }


 }

 int main()
 {
 int a[13]={'1','2','3','-1','4','-1','5','6','7','8','-1','9','10'};
struct node * root=constructBT(0,a,13);
preorder(root);
printf("\n");
postorder(root);
printf("\n");

inorder(root);
return 0;

 }

