#include<stdio.h>
#include<queue>
#include <string.h>
#include<limits.h>
using namespace std;



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
        if(h->array2[(pos-1)/2]>h->array2[pos])
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

void insert_element(struct heap * h,int d,int p)
{
h->array2[h->count]=p;
h->array1[h->count++]=d;
percolateup(h,h->count-1);

}
void percolatedown(struct heap * h,int pos)
{
    int save;
    int min=h->array2[pos];
    int min1=h->array1[pos];
    int replace=0;
    if(2*pos+1<h->count&&min>h->array2[2*pos+1])
    {   save=2*pos+1;
        replace=1;
        min=h->array2[2*pos+1];
        min1=h->array1[2*pos+1];
    }
    if(2*pos+2<h->count&&min>h->array2[2*pos+2])
    {   save=2*pos+2;
         replace=1;
        min=h->array2[2*pos+2];
        min1=h->array1[2*pos+2];
    }

    if(replace)
    {
        int tmp=h->array2[pos];
        int tmp1=h->array1[pos];

        h->array2[pos]=min;
        h->array1[pos]=min1;


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

int delete_element(struct heap * h,int e)
{
    for(int i=0;i<h->count;i++)
        if(h->array1[i]==e)
    {   h->array1[i]=h->array1[h->count-1];
        h->array2[i]=h->array2[h->count-1];
        h->count--;
        percolatedown(h,i);

        break;
    }

}

void push(struct heap *h,int e,int p)
{
insert_element(h,e,p);
}

int pop(struct heap *h)
{
return delete_max(h);
}
void set_priority(struct heap * h,int e,int p)
{
    delete_element(h,e);
    insert_element(h,e,p);

}
int empty(struct heap * h)
{
if(h->count==0)
    return 1;
else
    return 0;
}

























void shortestpath()
{
struct heap * h=create_heap(100);

int   adj[5][5]={{-1,+4,+1,-1,-1},
                 {+4,+0,+2,-1,+4},
                 {+1,+2,-1,+4,-1},
                 {-1,-1,+4,-1,+4},
                 {-1,+4,-1,+4,-1}};
int edges=5;
int root=0;


int distance[edges];
//memset(distance,INT_MAX,sizeof(int)*5);    cant use memset in c for values other than char
fill(distance,distance+edges,INT_MAX);

distance[root]=0;

push(h,root,distance[root]);
int path[edges];
path[root]=root;

while(!empty(h))
{


    int c=pop(h);


    for(int i=0;i<edges;i++)
        {
            int new_dist=distance[c]+adj[c][i];
            //printf("dist is %d %d \n",new_dist,distance[i]);
            if(new_dist<distance[i]&&adj[c][i]!=-1)
                {
                   path[i]=c;
                    distance[i]=new_dist;
                set_priority(h,i,new_dist);
                }
        }


}

for(int i=0;i<edges;i++)
    printf("distance= %d  last= %d \n",distance[i],path[i]);
    printf("\n");


}


int main()
{
shortestpath();

}


