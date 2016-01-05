#include<iostream>

using namespace std;

int binary(int a[],int s,int e,int key)
{
    if(s<=e)
    {
    int m=s+(e-s)/2;

    if(a[m]<key)
       return binary(a,m+1,e,key);
    else if(a[m]>key)
       return binary(a,s,m-1,key);
    else
        return m;

    }
    else
        return -1;

}

int main()
{
int arr[]={1,2,4,55,115,123};
int size=sizeof(arr)/sizeof(arr[0]);

cout<<binary(arr,0,size-1,33)<<endl;
}
