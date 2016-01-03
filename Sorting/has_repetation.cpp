#include<iostream>

using namespace std;

void merge(int a[],int s,int m,int e)
{


    int * l=new int[m-s+1];
    int * r=new int[e-m];

    for(int i=0;i<m-s+1;i++)
        l[i]=a[i+s];
    for(int i=0;i<e-m;i++)
        r[i]=a[i+m+1];



    int c1=0;
    int c2=0;
    int c3=s;

    while(c1<=m-s&&c2<e-m)
    {
        if(l[c1]<r[c2])
            a[c3++]=l[c1++];
        else
            a[c3++]=r[c2++];

    }

    while(c1<=m-s)
        a[c3++]=l[c1++];

    while(c2<e-m)
        a[c3++]=r[c2++];

}




void mergesort(int a[],int s,int e)
{


if(s<e)
{
    int mid=s+(e-s)/2;


mergesort(a,s,mid);
mergesort(a,mid+1,e);
merge(a,s,mid,e);
}




}













int main()
{
int arr[]={2,34,132,4,1,244,1};
int size=sizeof(arr)/sizeof(int);
mergesort(arr,0,size-1);
int flag=0;
for(int i=0;i<size;i++)
    if(arr[i]==arr[i+1])
        {flag=1;
        break;
        }

if(flag)
    cout<<"contains repeated elements"<<endl;
else
    cout<<"does not contain repeated element"<<endl;

}
