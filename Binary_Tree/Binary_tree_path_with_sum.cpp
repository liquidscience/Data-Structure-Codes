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
     {if(arr[pos]!=-1)
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




    int path_with_sum(node * root,int sum)
    {

        if(root->data>sum)
            return 0;
        else if (root->data<sum)
        {   int left=0,right=0;
            if(root->left_child)
                left=path_with_sum(root->left_child,sum-root->data);
            if(root->right_child)
                right=path_with_sum(root->right_child,sum-root->data);

        if (left||right)
            return 1;
        else
            return 0;


        }
        else
            return 1;




    }












 int main()
 {
 int a[13]={1,2,3,-1,4,-1,5,6,7,8,-1,9,10};
 int a1[13]={'1','2','3','a','4','s','5','6','7','8','h','9','10'};
struct node * root1=constructBT(0,a,13);
struct node * root2=constructBT(0,a1,13);

int display[13];
root_to_leaf(root1,display,0);

printf("%d",path_with_sum(root1,));
return 0;

 }

