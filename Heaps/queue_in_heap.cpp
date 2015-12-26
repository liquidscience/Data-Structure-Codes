#include<iostream>
#include<stdio.h>


struct heap
{
int * array1;
int * array2;
int count;
int capacity;

};


struct heap * create_heap(int size)
{

struct heap * h=new heap;

h->capacity=size;
h->count=0;
h->array1=new int[size];
h->array2=new int[size];
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
        if(h->array2[(pos-1)/2]<h->array2[pos])
            {
            int t=h->array2[(pos-1)/2];
            int t1=h->array1[(pos-1)/2];

            h->array2[(pos-1)/2]=h->array2[pos];
            h->array1[(pos-1)/2]=h->array1[pos];

            h->array2[pos]=t;
            h->array1[pos]=t1;

            percolateup(h,(pos-1)/2);
            }

    }

}



void print_heap(struct heap * h)
{
    for(int i=0;i<h->count;i++)
        printf("%d ",h->array1[i]);
        printf("\n");

}

void insert_element(struct heap * h,int d)
{
h->array2[h->count]=-h->count;
h->array1[h->count++]=d;
percolateup(h,h->count-1);

}
void percolatedown(struct heap * h,int pos)
{
    int save;
    int max=h->array2[pos];
    int max1=h->array1[pos];
    int replace=0;
    if(2*pos+1<h->count&&max<h->array2[2*pos+1])
    {   save=2*pos+1;
        replace=1;
        max=h->array2[2*pos+1];
        max1=h->array1[2*pos+1];
    }
    if(2*pos+2<h->count&&max<h->array2[2*pos+2])
    {   save=2*pos+2;
         replace=1;
        max=h->array2[2*pos+2];
        max1=h->array1[2*pos+2];
    }

    if(replace)
    {
        int tmp=h->array2[pos];
        int tmp1=h->array1[pos];

        h->array2[pos]=max;
        h->array1[pos]=max1;


        h->array2[save]=tmp;
        h->array1[save]=tmp1;

        percolatedown(h,save);

    }

}



int delete_max(struct heap * h)
{
    int e;
if(h->count>0)
{   e=h->array1[0];
    h->array1[0]=h->array1[h->count-1];
    h->array2[0]=h->array2[h->count-1];
    h->count--;
    percolatedown(h,0);
}

return e;
}

void push(struct heap *h,int e)
{
insert_element(h,e);
}

int pop(struct heap *h)
{
return delete_max(h);
}


int main()
{
struct heap * h=create_heap(100);
push(h,1);
push(h,2);
push(h,3);
push(h,4);

printf("%d\n",pop(h));
printf("%d\n",pop(h));
printf("%d\n",pop(h));

}
