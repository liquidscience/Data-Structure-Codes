#include<algorithm>
#include<iostream>
using namespace std;


int main()
{
int a[]={3,-2,1,96,-75,-29,33,-66,199,-15};

int size=sizeof(a)/sizeof(a[0]);

sort(a,a+size);

int close=10000;
for(int i=size-1;i>1;i--)
{
int k=a[i];
int low=0;
int high=i-1;
while(high!=low)
    {
        if(a[high]+a[low]==0)
            break;

        if(a[high]+a[low]>0)
           {
               if(a[high]+a[low]<close)
                close=a[high]+a[low];
             high--;
           }
        else
            {
                if(abs(a[high]+a[low])<close)
                close=abs(a[high]+a[low]);
                low++;

            }
    }
}


cout<<close<<endl;


}

