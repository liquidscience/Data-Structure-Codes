#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
int data;
struct node * next;

};

int isempty(struct node * head)
{
if(head==NULL)
return 1;
else
return 0;

}


void push(struct node ** head,int item)
{
struct node * temp=(struct node *)malloc(sizeof(struct node));
temp->data=item;
temp->next=*head;
*head=temp;
printf("%d pushed \n",item);

}
int pop(struct node **head)
{ int t;
if(isempty(*head))
{printf("ERR:POP():already empty \n");
return INT_MIN;
}
else
{
t=(*head)->data;
*head=(*head)->next;
return t;

}

}

void peek(struct node * st)
{
if(isempty(st))
{
    printf("PEEK ERROR EMPTY STACK");
return INT_MIN;
}
else
return st->data;

}


void main()
{
struct node * st=NULL;

char str[]="samplestring";
int n=0;
while(str[n])
{
push(&st,str[n]);
n++;
}
while(!isempty(st))
{

printf("%c",pop(&st));

}







}

