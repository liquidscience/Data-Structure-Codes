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

int get_size(node * root)
{
if(root==NULL)
return 0;

return 1+get_size(root->left_child)+get_size(root->right_child);

}


 int main()
 {
 int a[13]={'1','2','3','-1','4','-1','5','6','7','8','-1','9','10'};
struct node * root=constructBT(0,a,13);

printf("% d ",get_size(root));
return 0;

 }

