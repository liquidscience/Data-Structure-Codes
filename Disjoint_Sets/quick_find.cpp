#include<stdio.h>


struct sets
{
int * arr;
int size;
};
struct sets * make_sets(int s)
{
struct sets * s1=new sets;
s1->arr=new int [s];
for(int i=0;i<s;i++)
    s1->arr[i]=i;

s1->size=s;
return s1;
}

int _find(struct sets * s,int pos)
{
return s->arr[pos];
}

void _union(struct sets * s,int pos1,int pos2)
{
    int f1=_find(s,pos1);
    int f2=_find(s,pos2);


    if(!(f1==f2))
        for(int i=0;i<s->size;i++)
        {
            if(s->arr[i]==f1)
                {s->arr[i]=f2;}
        }

}


void print(struct sets * s)
{
    for(int i=0;i<s->size;i++)
        printf("%d ",s->arr[i]);
    printf("\n");
}

int main()
{
struct sets * s=make_sets(15);

_union(s,0,1);
_union(s,2,1);
_union(s,2,3);
_union(s,4,5);
_union(s,7,6);
_union(s,8,5);


print(s);


}
