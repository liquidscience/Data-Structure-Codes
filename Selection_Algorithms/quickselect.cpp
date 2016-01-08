#include<iostream>

using namespace std;

int partition(int a[],int s,int e)
{
int i=s-1;
int pivot=a[e];

for(int j=s;j<e;j++)
if(a[j]<=pivot)
    {
        int temp=a[++i];
        a[i]=a[j];
        a[j]=temp;

    }
a[e]=a[++i];
a[i]=pivot;


return i;
}

int quickselect(int a[],int s,int e,int order)
{
    if(s<=e)
    {

    int m=partition(a,s,e);
    //cout<<"operating on "<<s<<" to "<<e<<" with m= "<<m<<endl;
    if(order<m)
        return quickselect(a,s,m-1,order);
    else if(order>m)
        return quickselect(a,m+1,e,order);
    else
        return a[m];

    }

}

int main()
{
int a[]={9,8,7,6,5,3,1};
//1,3,5,6,7,8,9
int size=sizeof(a)/sizeof(a[0]);
for(int i=0;i<size;i++)
cout<<quickselect(a,0,size-1,i)<<endl;



}
