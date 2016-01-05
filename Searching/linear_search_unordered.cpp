#include<iostream>

using namespace std;

void linear(int a[],int n,int key)
{
    int i;
for(i=0;i<n;i++)
{if(a[i]==key)
break;
}

if(i!=n)
cout<<key<<"is present at loc"<<i<<endl;
else
cout<<"Not found";

}

int main()
{
int arr[]={1,2,4,123,55,3};
int size=sizeof(arr)/sizeof(arr[0]);

linear(arr,size,55);
}
