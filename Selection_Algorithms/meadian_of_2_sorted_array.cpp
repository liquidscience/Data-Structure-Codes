#include<iostream>
#include<limits.h>

using namespace std;

int median(int a[],int h,int s)
{
if((h-s)%2==1)
{
return (a[(s+(h-s)/2)]+a[(s+1+(h-s)/2)])/2;
}
else
return a[s+(h-s)/2];


}



int btree(int a[],int ah,int al,int b[],int bh,int bl)
{

cout<<"al="<<al<<" ah="<<ah<<" bl="<<bl<<" bh="<<bh<<endl;

if(ah-al+bh-bl<4)
{
    int a1=a[al];
    int b1=b[bl];
    int c1;
    if(ah!=al)
        c1=al+1;
    else if(bh!=bl)
        c1=bl+1;
    else
        c1=INT_MIN;

 return max(min(a1,b1), min(max(a1,b1),c1));


}





int am=median(a,ah,al);
int bm=median(b,bh,bl);




if(am==bm)
    return am;
else if(am>bm)
return btree(a,al+(ah-al)/2,al,b,bh,bl+(bh-bl)/2+1);
else
return btree(a,ah,al+1+(ah-al)/2,b,bl+(bh-bl)/2,bl);






}
int main()
{

    int ar1[] = {1, 2, 3, 6};
    int ar2[] = {4, 6, 8, 10};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);

    cout<<btree(ar1,n1-1,0,ar2,n2-1,0);

}

