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
//printf("%d pushed \n",item);

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
int peek(struct node * st)
{
if(isempty(st))
  { printf("stack is empty");
return INT_MIN;
}
int t=st->data;

return t;
}

void convert(char * exp)
{
struct node * st=NULL;
int priority[1000];
priority['(']=-1;
priority['+']=0;
priority['-']=0;
priority['*']=1;
priority['/']=1;
priority['^']=2;



int n=0;
while(exp[n])
{ char t;
char  ch=exp[n];
//printf("%c",ch);

if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
{
printf("%c",ch);

}

else if(ch=='(')
{
push(&st,'(');

}
else if(ch==')')
{
while((t=pop(&st))!='(')
  printf("%c",t);
}
else
{
if(isempty(st))
{
   push(&st,ch);
}
else
{
   if(priority[peek(st)]<priority[ch])
        push(&st,ch);
   else
   {
      while(!isempty(st)&&(priority[peek(st)]>=priority[ch]))
            {
            printf("%c",pop(&st));


            }
            push(&st,ch);
   }


}
}

n++;
}
while(!isempty(st))
{
  printf("%c",pop(&st));

}

}



void main()
{
char exp[]="a+b*c+d";
convert(exp);

}
