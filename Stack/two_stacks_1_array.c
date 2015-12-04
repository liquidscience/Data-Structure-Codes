#include <stdio.h>
#include<stdlib.h>

struct twostacks
{
	int top1;
	int top2;
	int size;
	int * arr;
	
	};
struct twostacks * initialize_two_stacks(int size)
{
	struct twostacks * tmp=(struct twostacks * )malloc(sizeof(struct twostacks));
	tmp->top1=-1;
	tmp->top2=size;
	tmp->size=size;
	tmp->arr=(int *)malloc(sizeof(int)*size);
	return tmp;
	}
	
	
void push1(struct twostacks * ts,int item)
{
	if(ts->top2-ts->top1>1)
	{
		
		ts->arr[++ts->top1]=item;
	}
	else
	{
		printf("stack 1 full!");
		
	}
	
	
}
void push2(struct twostacks * ts,int item)
{
	if(ts->top2-ts->top1>1)
	{
		
		ts->arr[--ts->top2]=item;
	}
	else
	{
		printf("stack 2 full!");
		
	}
	
	
}

int pop1(struct twostacks * ts)
{
	if(ts->top1>-1)
	{
		
		return ts->arr[ts->top1--];
	}
	else
	{
		printf("stack 1 already empty!");
		
	}
	
	
}

int pop2(struct twostacks * ts)
{
	if(ts->top2<ts->size)
	{
		
		return ts->arr[ts->top2++];
	}
	else
	{
		printf("stack 2 already empty!");
		
	}
	
	
}

int main(void) {
	
	struct twostacks * ts=initialize_two_stacks(6);
	
	
	push1(ts,1);
	push2(ts,1);
	push1(ts,2);
	push2(ts,2);
	push1(ts,3);
	push2(ts,3);
	
	printf("%d ",pop1(ts));
	push2(ts,4);
	printf("%d ",pop1(ts));
	printf("%d ",pop1(ts));
	push2(ts,5);
	push2(ts,6);
	push2(ts,7);
	
	
	
	
	
	return 0;
}
