#include <iostream>       // std::cout
#include <stack>
#include<stdio.h>
#include<queue>

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






 void level_order(struct node * root)
 {
     if(root!=NULL)
     {
         queue<node *>q;
         q.push(root);

         while(!q.empty())
         {
           struct  node * top =q.front();
             q.pop();
             printf("%c \n",top->data);
             if(top->left_child!=NULL)
                q.push(top->left_child);
             if(top->right_child!=NULL)
                q.push(top->right_child);


         }


     }



 }

 int main()
 {
 int a[13]={'1','2','3','-1','4','-1','5','6','7','8','-1','9','10'};
struct node * root=constructBT(0,a,13);

level_order(root);
return 0;

 }

