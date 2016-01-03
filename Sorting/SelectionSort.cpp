#include<iostream>

using namespace std;

void selectionsort(int arr[],int size)
{


for(int j=0;j<size-1;j++)
    {
      int min=arr[j];
      int pos=j;
      for(int i=j+1;i<size;i++)
        {
            if(arr[i]<min)
                {min=arr[i];
                pos=i;
                }
        }
     int t=arr[pos];
     arr[pos]=arr[j];
     arr[j]=t;

}

for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";


}




int main()
{
int arr[]={2,34,132,4,1,244};
selectionsort(arr,6);

}
