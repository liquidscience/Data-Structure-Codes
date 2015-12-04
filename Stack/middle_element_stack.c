#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
struct node
{
    struct node * next;
    struct node * prev;
    int data;
};

struct middle_stack
{
    struct node * head;
    struct node * middle;
    int size;
};

struct middle_stack * init_middle_stack()
{
    struct middle_stack * t=(struct middle_stack *)malloc(sizeof(struct middle_stack));
    t->head=(struct node *)malloc(sizeof(struct node));
    t->middle=(struct node *)malloc(sizeof(struct node));
    t->head=NULL;
    t->middle=NULL;
    t->size=0;
    return t;
};

void push(struct middle_stack * stack,int data)
{   stack->size++;
//printf("cur stack size =%d \n",stack->size);
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->next=stack->head;
    temp->data=data;

    if(stack->head!=NULL)
        stack->head->prev=temp;

    stack->head=temp;


   if(stack->size==1)
      stack->middle=stack->head;

   else if(((stack->size)&1)==0)
   {  // printf("entered for size %d \n",stack->size);
       stack->middle=stack->middle->prev;
   }



}

int pop(struct middle_stack * stack)
{ struct node * temp;
    if(stack->head!=NULL)
    {
        stack->size--;


        temp=stack->head;
        stack->head=stack->head->next;

    if(stack->size==0)
        stack->middle=NULL;

    else if(stack->size&1==1)
     stack->middle=stack->middle->next;

     return temp->data;
    }
    else
        return INT_MIN;

}
void get_middle(struct middle_stack * stack)
{
    if(stack->head!=NULL)
        printf(" %d \n",stack->middle->data);
    else
        printf("empty");

}


void main()
{
    struct middle_stack * ms=init_middle_stack();

    push(ms, 11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
    push(ms, 66);
    push(ms, 77);

    printf("Item popped is %d\n", pop(ms));
    printf("Item popped is %d\n", pop(ms));
  get_middle(ms);






}
