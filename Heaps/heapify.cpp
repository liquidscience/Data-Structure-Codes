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


void heapify(struct heap * heap,int pos)
{   int pos1=-1;
    if(pos>parent_node(heap->count-1))
        return;

    int max=heap->array[pos];
    int lchild=left_node(pos);
    int rchild=right_node(pos);

    //printf("i was here");
    if(lchild<heap->count&&max<heap->array[lchild])
    {
        max=heap->array[lchild];
        pos1=lchild;
        //printf("i was here too");
    }
    if(rchild<heap->count&&max<heap->array[rchild])
    {
        max=heap->array[lchild];
        pos1=rchild;
    }
    if(pos1!=-1)
     {   int t=heap->array[pos];
            heap->array[pos]=heap->array[pos1];
            heap->array[pos1]=t;
         heapify(heap,pos1);
     }

}
int delete_element(struct heap * h)
{
    if(h->count==0)
        return -1;
    int d=h->array[0];
    h->array[0]=h->array[h->count-1];
    heapify(h,0);
    return d;

}

void percolateup(struct heap * h,int pos)
{
    if((pos-1)/2>=0)
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


void insert(struct heap * h,int d)
{

    h->count++;
    h->array[h->count-1]=d;
    percolateup(h,h->count-1);


}

void print_heap(struct heap * h)
{
    for(int i=0;i<h->count;i++)
        printf("%d ",h->array[i]);

}

int main()
{
struct heap * h=create_heap(100);
h->array[0]=31;
h->array[1]=1;
h->array[2]=21;
h->array[3]=5;
h->array[4]=10;
h->array[5]=12;
h->array[6]=18;
h->array[7]=3;
h->array[8]=2;
h->array[9]=8;
h->array[10]=7;



h->count=11;
heapify(h,1);
print_heap(h);
}
