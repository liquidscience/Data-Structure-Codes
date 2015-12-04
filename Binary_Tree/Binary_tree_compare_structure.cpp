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

int struct_match(node * root1,node * root2)
{
    if(root1==NULL&&root2!=NULL||root2==NULL&&root1!=NULL)
        return 0;
    if(root1==NULL&&root2==NULL)
        return 1;
    else
    {
         if(struct_match(root1->left_child,root2->left_child)&&struct_match(root1->right_child,root2->right_child))
            return 1;

        else
            return 0;

    }


}










 int main()
 {
 int a[13]={'1','2','3','-1','4','-1','5','6','7','8','-1','9','10'};
 int a1[13]={'1','2','3','a','4','s','5','6','7','8','h','9','10'};
struct node * root1=constructBT(0,a,13);
struct node * root2=constructBT(0,a1,13);
printf("%d ",struct_match(root1,root2));
return 0;

 }

