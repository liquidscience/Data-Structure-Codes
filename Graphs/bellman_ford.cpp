#include<stdio.h>
#include<queue>
#include <string.h>
#include<limits.h>
#include<set>
using namespace std;


void shortestpath()
{
queue<int> q;
set<int> s;
int   adj[5][5]={{+1,+4,+1,+1,-1},
                 {+4,+0,+2,+1,+4},
                 {+1,+2,-1,+4,+1},
                 {+1,+1,+4,+1,+4},
                 {+1,+4,-1,+4,+1}};
int edges=5;
int root=0;


int distance[edges];
//memset(distance,INT_MAX,sizeof(int)*5);    cant use memset in c for values other than char
fill(distance,distance+edges,INT_MAX);

distance[root]=0;

s.insert(0);
q.push(0);

while(!q.empty())
{


    int c=q.front();
    q.pop();
    s.erase(c);

    for(int i=0;i<edges;i++)
        {
            int new_dist=distance[c]+adj[c][i];
            //printf("dist is %d %d \n",new_dist,distance[i]);
            if(new_dist<distance[i]&&adj[c][i]!=-1)
                {
                   // printf("passed for %d \n",i);
                    distance[i]=new_dist;
                if(s.count(i)==0)
                {
                    q.push(i);
                    s.insert(i);
                }
                }
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


