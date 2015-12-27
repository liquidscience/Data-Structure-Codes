#include<stdio.h>
#include<queue>
#include <string.h>
using namespace std;
void bfs()
{


int   adj[5][5]={{0,0,0,0,1},
                {0,0,1,1,1},
                {0,1,0,1,0},
                {0,1,1,0,1},
                {1,1,0,1,0}};
int edges=5;
int root=0;

queue<int> st;
st.push(root);
int marked[edges];
memset(marked,0,sizeof(int)*5);
 marked[0]=1;
while(!st.empty())
{

    int c=st.front();
    st.pop();

    for(int i=0;i<edges;i++)
        {   //printf("2 vals are %d %d\n",marked[i],adj[c][i]);
            if(marked[i]==0&&adj[c][i]==1)
                {marked[i]=1;
                st.push(i);}
        }

    printf("%d\n",c);
}

}


int main()
{


bfs();

}


