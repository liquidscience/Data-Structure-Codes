#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
int data;
struct node * next;

};


void push(struct node **head,struct node ** min,int data)
{
struct node * tmp=(struct node *)malloc(sizeof(struct node));
tmp->data=data;
tmp->next=*head;
*head=tmp;
if(isempty())
{struct node * tmp1=(struct node *)malloc(sizeof(struct node));
tmp1->data=size(*head);
tmp1->next=*min;
*min=tmp;
}
else
{
    if(peek(*min)>data)
    {struct node * tmp1=(struct node *)malloc(sizeof(struct node));
    tmp1->data=size(*head);
    tmp1->next=*min;
    *min=tmp1;
    }

}


}

int pop(struct node ** head,struct node **min)
{ int d;
struct node * temp;

if(!isempty(*head))
{

temp=*head;
*head=(*head)->next;
d=temp->data;

if(size(*head)>peek(*min))
*min=(*min)->next;

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

int size(struct node * st)
{ int i=0;
    while(st!=NULL)
    {i++;
    st=st->next;
}
return i;
}

void main()
{

}

