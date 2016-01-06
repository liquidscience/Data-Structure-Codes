#include<algorithm>
#include<iostream>
using namespace std;


int main()
{
int a[]={3,2,1,96,-75,-29,33,-66,199,-15};

int size=sizeof(a)/sizeof(a[0]);

sort(a,a+size);
for(int i=size-1;i>1;i--)
{
int k=a[i];
int low=0;
int high=i-1;
while(high!=low)
    {
        if(a[high]+a[low]==k)
            break;

        if(a[high]+a[low]>k)
            high--;
        else
            low++;
    }
if(high!=low)
{cout<<a[low]<<"+"<<a[high]<<endl;
break;
}

}



}
