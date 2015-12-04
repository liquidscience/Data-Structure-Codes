#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
struct stack
{
  int size;
  int * arr;
  int top;

};

struct stack * createstack(int size)
{
struct stack * st  =(struct stack *)malloc(sizeof(struct stack));
st->size=size;
st->arr=(int *)malloc(sizeof(int)*size);
st->top=-1;
return st;
}

int isempty(struct stack * st)
{
    if(st->top<0)
       return 1;
    else
       return 0;

}

int isfull(struct stack * st)
{
    if(st->top>=st->size-1)
        return 1;
     else
         return 0;
}


void push(struct stack* st, int item)
{
    if (isfull(st))
       {
        printf("ERR:Push():Stack is full \n");

       }
       else
       {
        st->arr[++st->top] = item;
        printf("%d pushed to stack\n", item);

        }

}


int pop(struct stack * st)
{
if(isempty(st))
{
    printf("ERR:Pop():Stack is already empty \n");
    return INT_MIN;
}
else
{

    return (st->arr[st->top--]);

}


}

int peek(struct stack * st)
{
if(isempty(st))
{
printf("ERR:Peek():Stack is already empty \n ");
return INT_MIN;
}
else
{
return st->arr[st->top];

}
}





void main()
{
struct stack * st=createstack(3);
push(st, 10);
    push(st, 20);
    push(st, 30);
    push(st,40);
    peek(st);
   printf("%d \n",pop(st));
    printf("%d \n",pop(st));
    printf("%d \n",pop(st));
    pop(st);

}


