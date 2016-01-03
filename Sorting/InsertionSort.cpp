#include<iostream>

using namespace std;

void selectionsort(int a[],int size)
{


for(int j=1;j<size;j++)
{   int i=0;


    while(a[i]<a[j]&&i<j)
    {i++;}


        int t=a[j];
        int j1=j;
        while(j1>i)
        {
            a[j1]=a[j1-1];
            j1--;
        }
        a[i]=t;



}

for(int i=0;i<size;i++)
    cout<<a[i]<<" ";


}




int main()
{
int arr[]={2,34,132,4,1,244};
selectionsort(arr,6);

}
