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

temp=*head;
*head=(*head)->next;
d=temp->data;

free(temp);
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

void reverse_stack(struct node ** stack)
{ int tmp;
if(isempty(*stack))
{
    return;
}
else
{
    tmp=pop(stack);
  reverse_stack(stack);
  insert_at_bottom(stack,tmp);


}
}


void insert_at_bottom(struct node ** stack,int val)
{   int temp;
    if(isempty(*stack))
      {push(stack,val);
      return;
      }
     temp=pop(stack);
     insert_at_bottom(stack,val);
     push(stack,temp);

}




void main()
{
struct node * stack1=NULL;
push(&stack1,1);
push(&stack1,2);
push(&stack1,3);
push(&stack1,4);
push(&stack1,5);
reverse_stack(&stack1);
printf("%d ",pop(&stack1));
printf("%d ",pop(&stack1));
printf("%d ",pop(&stack1));
printf("%d ",pop(&stack1));
printf("%d ",pop(&stack1));

}

