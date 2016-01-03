#include<iostream>

using namespace std;

void bubblesort(int arr[],int size)
{


for(int j=0;j<size-1;j++)
for(int i=0;i<size-j-1;i++)
{
    if(arr[i]>arr[i+1])
    {   int t=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=t;
    }

}


for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";


}




int main()
{
int arr[]={2,34,132,4,1,244};
bubblesort(arr,6);

}
