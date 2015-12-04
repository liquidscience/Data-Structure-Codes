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

void push_min(struct node ** st,struct node **min,int data)
{

    push(st,data);
    if(isempty(*min))
        push(min,data);
    else if(peek(*min)>=data)
       push(min,data);
}

int pop_min(struct node ** st,struct node **min)
{
    if(isempty(*st))
    {
        return INT_MAX;
    }
   int d= pop(st);
   if(d==peek(*min))
     pop(min);
    return d;

}



void main()
{
struct node * st=NULL;
struct node *min=NULL;
push_min(&st,&min,7);
push_min(&st,&min,9);
push_min(&st,&min,11);
push_min(&st,&min,6);
push_min(&st,&min,1);
pop_min(&st,&min);
printf(" min now %d \n",peek(min));
pop_min(&st,&min);
printf(" min now %d \n",peek(min));
pop_min(&st,&min);
printf(" min now %d \n",peek(min));
pop_min(&st,&min);
printf(" min now %d \n",peek(min));
pop_min(&st,&min);


}

