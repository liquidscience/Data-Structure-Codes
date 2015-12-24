#include<stdio.h>
#include<iostream>

struct heap
{
    int * array;
    int size;
    int count;
};
void printheap(struct heap * h)
{
    for(int i=0;i<h->count;i++)
        printf("%d ",h->array[i]);


}

struct heap * createheap(int s)
{
    struct heap * h=new heap;
    h->size=s;
    h->count=0;
    h->array=new int[s];
    return h;

}
void percolate_down(struct heap * h,int pos)
{
    int max=h->array[pos];
    bool change=false;
    int pos_save;

    if(2*pos-1<h->count&&h->array[2*pos+1]>max)
    {   pos_save=2*pos+1;
        max=h->array[2*pos+1];
        change=true;
    }
     if(2*pos+2<h->count&&h->array[2*pos+2]>max)
    {   pos_save=pos*2+2;
        max=h->array[2*pos+2];
        change=true;
    }

    if(change)
    {
        int tmp=h->array[pos];
        h->array[pos]=h->array[pos_save];
        h->array[pos_save]=tmp;
        percolate_down(h,pos_save);

    }



}


void heap_to_array(struct heap * h,int data[],int size)
{


    if(h->size-h->count<size)
       {
         printf("overflow");
         return;
       }
    for(int i=0;i<size;i++)
    {
        h->array[h->count+i]=data[i];
    }


    h->count=h->count+size;


    int last_nonleaf=(h->count-1)/2;
    for(int j=last_nonleaf;j>=0;j--)
        percolate_down(h,j);
}


void heapsort(struct heap * h)
{
    while(h->count>0)
    {
    int d=h->array[0];
    h->array[0]=h->array[h->count-1 mn,];
    h->count--;
    percolate_down(h,0);
    printf("%d ",d);

    }

}




int main()
{
   struct heap * h=createheap(100);
   int a[]={1,2,3,4,5,6,7,8,9,10};
    heap_to_array(h,a,10);
   heapsort(h);

}
