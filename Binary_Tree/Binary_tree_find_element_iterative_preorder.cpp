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

void finder(node * root,char d)
{
    stack<node *> st;

    if(root!=NULL)
    {
            while(1)
        {
            while(root)
            {   st.push(root);
                if(root->data==d)
                    {printf("found %c ",d);
                    return;}
                root=root->left_child;

            }

            if(st.empty())
                break;

            root=st.top();
            st.pop();
            root=root->right_child;




        }
        printf("dint find");

    }
}










 int main()
 {
 int a[13]={'1','2','3','-1','4','-1','5','6','7','8','-1','9','10'};
struct node * root=constructBT(0,a,13);

finder(root,'3');
return 0;

 }

