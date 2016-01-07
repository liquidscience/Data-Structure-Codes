#include<iostream>

using namespace std;

int bsearch(int a[],int s,int e)
{


int m=s+(e-s)/2;
if(a[m]>a[m+1]&&a[m]>a[m-1])
    return a[m];
else if (a[m]>a[m-1]&&a[m+1]>a[m])
    return bsearch(a,m,e);
else if(a[m]<a[m-1]&&a[m+1]<a[m])
    return bsearch(a,s,m);


}

int main()
{
int a[]={1,2,3,4,5,6,7,8,1};
int size=sizeof(a)/sizeof(a[0]);
cout<<bsearch(a,0,size-1);



}
