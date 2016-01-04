#include<iostream>

using namespace std;

int partition(int a[],int s,int e)
{


int i=s-1;int t;
int key=a[e];

for(int j=s;j<e;j++)
{
    if(a[j]<=key)
    {    t=a[++i];
        a[i]=a[j];
        a[j]=t;
    }

}

a[e]=a[i+1];
a[i+1]=key;

return i+1;

}


void quicksort(int a[],int s,int e)
{
    if(s<e)
    {
    int m=partition(a,s,e);
    quicksort(a,s,m-1);
    quicksort(a,m+1,e);
    }
}


int main()
{
int arr[]={2,34,132,4,1,244,1};
int size=sizeof(arr)/sizeof(arr[0]);
quicksort(arr,0,size-1);

for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";



}
