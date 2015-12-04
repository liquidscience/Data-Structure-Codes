#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
int data;
struct node * next;

};


void push(struct node **head,int data)
{
struct node * tmp=(struct node *)malloc(sizeof(struct node));
tmp->data=data;
//printf("%d data here \n",tmp->data);
tmp->next=*head;

*head=tmp;
//printf("%d  \n",(*head)->data);



}

int pop(struct node ** head)
{ int d;
struct node * temp;

if(!isempty(*head))
{
/*temp=(*head)->next;
*head=temp;
d=temp->data;
*/
temp=*head;
*head=(*head)->next;
d=temp->data;
//printf("%d",d);
//free(temp);
return d;
}
else
    return INT_MIN;


}

int isempty(struct node * n)
{
    if(n==NULL)
        return 1;
    else
        return 0;
}

int peek(struct node * n)
{
if(!isempty(n))
{

return n->data;
}
else
{
  return INT_MIN;
}


}



void main()
{
struct node * stack1=NULL;
 int arr[]= {11, 13, 21, 3};
 int t;int d;
 int i=sizeof(arr)/sizeof(int);
 int ans[i];
 i=i-1;
while(i>=0)
{
    if(isempty(stack1))
       ans[i]=-1;
    else
    {
       while(!isempty(stack1)&&peek(stack1)<=arr[i])
       {
           pop(&stack1);
       }

       if(isempty(stack1))
        ans[i]=-1;
       else
        ans[i]=peek(stack1);


    }
    push(&stack1,arr[i]);

i--;
}
i=0;
while(ans[i])
{
    printf("%d ",ans[i++]);
}

}

