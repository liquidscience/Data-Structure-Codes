#include<iostream>
#include<stack>
#include<limits.h>

using namespace std;

class graph
{
    int vertex;
    int **adj;

    public: graph(int m,int n);
    void add_edge(int s,int d,int w);

   public:
        void maxflow(int s,int d);

    void dfs(int s,int parent[],int visited[]);


};


graph::graph(int m,int n)
{
 vertex=m+n+2;
 adj=new int*[vertex];
 for(int i=0;i<vertex;i++)
    adj[i]=new int [vertex];

       for(int i=0;i<vertex;i++)
        {for(int j=0;j<vertex;j++)
            adj[i][j]=0;
        }


for(int i=1;i<=m;i++)
    add_edge(0,i,1);

for(int i=m+1;i<vertex-1;i++)
    add_edge(i,vertex-1,1);




}

void graph::add_edge(int s,int d,int w)
{
    adj[s][d]=w;
}

void graph::dfs(int s,int parent[],int visited[])
{


    visited[s]=1;
    for(int i=0;i<vertex;i++)
    {
        if(adj[s][i]>0&&visited[i]==0)
        {   parent[i]=s;
            //cout<<"setting parent of "<<i<<"as "<<s<<endl;
            dfs(i,parent,visited);
        }


    }


}




void graph::maxflow(int s,int d)
{



    int maxflow=0;
    int * visited=new int[vertex];
    fill(visited,visited+vertex,0);
    int * parent=new int[vertex];
    fill(parent,parent+vertex,-1);
    dfs(s,parent,visited);


      while(parent[d]!=-1)
       {

            int x=parent[d];
            int d1=d;
            int min=INT_MAX;

            while(x!=-1)
            {


                if(adj[x][d1]<min)
                    min=adj[x][d1];

                d1=x;
                x=parent[x];
            }


            x=parent[d];
            d1=d;

            while(x!=-1)
            {
                adj[x][d1]-=min;
                adj[d1][x]+=min;

                d1=x;
                x=parent[x];
            }



            fill(parent,parent+vertex,-1);
            maxflow+=min;
            fill(visited,visited+vertex,0);
            dfs(s,parent,visited);
       }



cout<<"maximum matching  is "<<maxflow<<endl;


}









int main()
{


    graph g1(6,6);
    g1.add_edge(1,2+6,1);
    g1.add_edge(1,3+6,1);
    g1.add_edge(3,1+6,1);
    g1.add_edge(3,4+6,1);
    g1.add_edge(4,3+6,1);
    g1.add_edge(5,3+6,1);
    g1.add_edge(5,4+6,1);
    g1.add_edge(6,6+6,1);




    g1.maxflow(0,13);



}
