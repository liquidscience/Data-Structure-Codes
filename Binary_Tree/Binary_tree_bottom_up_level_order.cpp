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

void level_reverse(node * root)
{   stack<char> st;
    if(root!=NULL)
    {
        queue<node *> q;
        q.push(root);
        while(!q.empty())
        {
            node * temp=q.front();
            q.pop();
            st.push(temp->data);


            if(temp->right_child)
                q.push(temp->right_child);
            if(temp->left_child)
                q.push(temp->left_child);



        }

        while(!st.empty())
            {
                printf("%c ",st.top());
                st.pop();

            }



    }



}


 int main()
 {
 int a[13]={'1','2','3','-1','4','-1','5','6','7','8','-1','9','10'};
struct node * root=constructBT(0,a,13);

level_reverse(root);
return 0;

 }

