#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
int data;
struct node * next;
struct node * prev;

};

struct stack
{
struct node * head;
int size;
struct node * mid;
};

struct stack * create_stack(struct stack * s)
{
    s=(struct stack *)malloc(sizeof(struct stack));
    s->head=NULL;
    s->size=0;
    s->mid=NULL;

}
void push(struct stack *s,int data)
{
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->prev=NULL;
    temp->next=s->head;


    s->size++;

    if(s->size==1)
    {
        s->mid=s->head;

    }
    else
    {
    if(s->size&1)
          {
               s->mid=s->mid->prev;

          }
       s->head->prev=temp;

    }

 s->head=temp;

}

int pop(struct node ** head)
{ int d;
struct node * temp;

if(!isempty(*head))
{
temp=*head;
*head=(*head)->next;
d=temp->data;
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
struct node *stack1=NULL;



}

