#include<stdio.h>
#include<queue>
#include <string.h>
using namespace std;
void shortestpath()
{


int   adj[5][5]={{0,1,0,0,1},
                {1,0,1,1,1},
                {0,1,0,1,0},
                {0,1,1,0,1},
                {1,1,0,1,0}};
int edges=5;
int root=0;

queue<int> st;
st.push(root);
int distance[edges];
memset(distance,-1,sizeof(int)*5);
 distance[root]=0;
while(!st.empty())
{

    int c=st.front();
    st.pop();

    for(int i=0;i<edges;i++)
        {
            if(distance[i]==-1&&adj[c][i]==1)
                {distance[i]=distance[c]+1;
                st.push(i);}
        }


}

for(int i=0;i<edges;i++)
    printf("%d ",distance[i]);
    printf("\n");


}


int main()
{
shortestpath();

}


