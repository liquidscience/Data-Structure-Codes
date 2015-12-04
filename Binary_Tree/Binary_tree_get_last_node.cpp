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

int last_finder(node * root)
{int level=0;node * temp;
    if(root==NULL)
        return 0;
    else
    {   int next=0;
        queue<node *> q;
        q.push(root);

        int  cur_level=1;
        while(!q.empty())
        {
         temp=q.front();
        q.pop();
        cur_level--;
        if(temp->left_child)
               {
               q.push(temp->left_child);
               next++;
               }
        if(temp->right_child)
                {q.push(temp->right_child);
                next++;
               }
            if(cur_level==0)
                {cur_level=next;
                    next=0;
                    level++;
                }

        }

    }
return temp->data;
}










 int main()
 {
 int a[13]={'1','2','3','-1','4','-1','5','6','7','8','-1','9','10'};
struct node * root=constructBT(0,a,13);

printf("%d ",last_finder(root)-'0');
return 0;

 }

