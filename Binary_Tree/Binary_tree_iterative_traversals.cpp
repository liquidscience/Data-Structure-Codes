#include <iostream>       // std::cout
#include <stack>
#include<stdio.h>


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


 void preorder(struct node * root)
 {
     stack<node *> st;
    while(1)
    {
    while(root!=NULL)
    {   //cout<<((char)root->data)<<endl;


        printf("%c \n",root->data);
        st.push(root);
        root=root->left_child;

    }

    if(st.empty())
        break;

    root=st.top();
  // printf("popped %c \n",root->data);
    st.pop();
    root=root->right_child;

  //  printf("to add %c \n",root->data);


    }


 }

 void postorder(struct node * root)
 {
  if(root!=NULL)
  {
   stack<node *> st;
   st.push(root);
   struct node * prev=NULL;

   while(!st.empty())
   {

    struct node * current =st.top();

    if(prev==NULL||prev->left_child==current||prev->right_child==current)
     {
         if(current->left_child!=NULL)
            st.push(current->left_child);
        else if (current->right_child)
             st.push(current->right_child);
        else
        {
            printf("%c \n",current->data);
            st.pop();


        }

     }
     else if(current->left_child==prev)
     {
         if(current->right_child!=NULL)
            st.push(current->right_child);
        else
            {printf("%c \n",current->data);
            st.pop();
            }

     }
     else{
        printf("%c \n",current->data);
        st.pop();

     }

     prev=current;

   }
  }
}



  void inorder(struct node * root)
 {
      stack<node *> st;
    while(1)
    {
    while(root!=NULL)
    {   //cout<<((char)root->data)<<endl;



        st.push(root);
        root=root->left_child;

    }

    if(st.empty())
        break;

    root=st.top();
  // printf("popped %c \n",root->data);
    st.pop();
    printf("%c \n",root->data);
    root=root->right_child;

  //  printf("to add %c \n",root->data);

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

