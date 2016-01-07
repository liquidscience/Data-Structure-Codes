#include<iostream>

using namespace std;

int bsearch(int a[],int s,int e,int key)
{
cout<<"solving for "<<s<<" and "<<e<<endl;

int m=s+(e-s)/2;
if(a[m]==key)
    return m;
else if(key>=a[s]&&key<a[m]||key>=a[s]&&key>a[m]&&a[s]>a[m])
        return bsearch(a,s,m-1,key);
else if(key>a[m]&&key<=a[e]||key>a[m]&&key>=a[e]&&a[m]>a[e])
    return bsearch(a,m+1,e,key);
else
    return -1;


}

int main()
{
int a[]={7,8,9,1,2,3,5,6};

int size=sizeof(a)/sizeof(a[0]);
for(int i=0;i<size;i++)
cout<<bsearch(a,0,size-1,a[i])<<endl;



}
