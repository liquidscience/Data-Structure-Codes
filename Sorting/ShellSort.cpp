#include<iostream>

using namespace std;

void shellsort(int a[],int size)
{


for(int gap=size/2;gap>0;gap/=2)
{
    for(int i=gap;i<size;i++)
    {
        int temp=a[i];
        int j;
        for(j=i;j>=gap&&a[j-gap]>a[j];j-=gap)
            a[j]=a[j-gap];
        a[j]=temp;


    }


}






for(int i=0;i<size;i++)
    cout<<a[i]<<" ";


}




int main()
{
int arr[]={2,34,132,4,1,244};
shellsort(arr,6);

}
