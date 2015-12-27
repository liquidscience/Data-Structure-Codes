#include<stdio.h>
#include<queue>
#include <string.h>
using namespace std;
void ts()
{


int   adj[5][5]={{0,0,0,0,1},
                 {1,0,0,1,1},
                 {0,1,0,1,0},
                 {0,0,0,0,1},
                 {0,0,0,0,0}};
int edges=5;
int indegree[edges];
memset(indegree,0,sizeof(int)*edges);
queue<int> st;
int marked[edges];
memset(marked,0,sizeof(int)*edges);


for(int i=0;i<edges;i++)
    for(int j=0;j<edges;j++)
{
    if(adj[i][j]==1)
        indegree[j]++;
}


for(int i=0;i<edges;i++)
    if(indegree[i]==0)
        {st.push(i);
        marked[i]=1;
        }



while(!st.empty())
{

    int c=st.front();
    st.pop();

    for(int i=0;i<edges;i++)
        {
            if(marked[i]==0&&adj[c][i]==1)
                {indegree[i]--;
                }
        }

    printf("%d\n",c);
    for(int i=0;i<edges;i++)
        if(marked[i]==0&&indegree[i]==0)
            {st.push(i);
            marked[i]=1;
            }


}

}


int main()
{


ts();

}


