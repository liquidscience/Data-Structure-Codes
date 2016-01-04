#include<iostream>

using namespace std;

int countingsort(int a[],int n,int k)
{
int c[k];
fill(c,c+k,0);
for(int i=0;i<n;i++)
    c[a[i]]++;

for(int i=1;i<k;i++)
   c[i]=c[i]+c[i-1];

int b[n];


for(int i=n-1;i>=0;i--)
{
    b[--c[a[i]]]=a[i];

}

for(int i=0;i<n;i++)
    cout<<b[i]<<" ";

}





int main()
{
int arr[]={3,3,3,2,2,1,1,0};
int size=sizeof(arr)/sizeof(arr[0]);
countingsort(arr,size,4);





}
