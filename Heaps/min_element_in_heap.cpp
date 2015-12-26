#include<iostream>
#include<stdio.h>


struct heap
{
int * array;
int count;
int capacity;

};


struct heap * create_heap(int size)
{

struct heap * h=new heap;

h->capacity=size;
h->count=0;
h->array=new int[size];
return h;

}

int parent_node(int i)
{

return (i-1/2);

}

int left_node(int i)
{

return i*2+1;
}

int right_node(int i)
{

return i*2+2;
}




void percolateup(struct heap * h,int pos)
{
    if(pos>0)
    {
        if(h->array[(pos-1)/2]<h->array[pos])
            {
            int t=h->array[(pos-1)/2];
            h->array[(pos-1)/2]=h->array[pos];
            h->array[pos]=t;
            percolateup(h,(pos-1)/2);
            }

    }

}



void print_heap(struct heap * h)
{
    for(int i=0;i<h->count;i++)
        printf("%d ",h->array[i]);

}

void insert_element(struct heap * h,int d)
{
h->array[h->count++]=d;
percolateup(h,h->count-1);

}

void min(struct heap * h)
{
int up=((h->count-1)-1)/2;
int min=100000;
for(int i=up+1;i<h->count;i++)
    if(min>h->array[i])
        min=h->array[i];

printf("\nmin was found as %d \n",min);
}

int main()
{
struct heap * h=create_heap(100);
insert_element(h,31);
insert_element(h,43);
insert_element(h,21);
insert_element(h,5);
insert_element(h,10);
insert_element(h,12);
insert_element(h,18);
insert_element(h,3);
insert_element(h,2);
insert_element(h,8);
insert_element(h,71);
min(h);


h->count=11;

print_heap(h);
}
