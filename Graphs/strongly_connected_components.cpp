#include<iostream>
#include<stack>
#include<limits.h>

using namespace std;

class graph
{
    int vertex;
    int ** adj;
        int * ftime;
    int  *visited;
    public:void scc();

    public: graph(int v);
    void add_edge(int s,int d);
    void dfs(int s);
    void transpose();
    int get_max();
    void dfs_t(int s);
};


graph::graph(int v)
{
 vertex=v;
 adj=new int*[v];
 for(int i=0;i<v;i++)
    adj[i]=new int [v];

       for(int i=0;i<vertex;i++)
        {for(int j=0;j<vertex;j++)
            adj[i][j]=0;

        }

  ftime=new int[vertex];
   visited=new int[vertex];

}

void graph::add_edge(int s,int d)
{
    adj[s][d]=1;
}
void graph::scc()
{

    for(int i=0;i<vertex;i++)
    {
        if(!(visited[i]==1))
        {
          dfs(i);
        }
    }


    transpose();


    for(int i=0;i<vertex;i++)
        visited[i]=0;

    int s=get_max();


    while(s>=0)
    {
        cout<<"the SCC is ";

        dfs_t(s);
        cout<<endl;
        s=get_max();
    }

}
int graph::get_max()
{

    int max=INT_MIN;
    int pos=-1;
    for(int i=0;i<vertex;i++)
    {
        if(max<ftime[i])
        {
            max=ftime[i];
            pos=i;
        }

    }
    return pos;

}
void graph::transpose()
{
    int **adj1;
    adj1=new int* [vertex];

    for(int i=0;i<vertex;i++)
    {
        adj1[i]=new int[vertex];
        for(int j=0;j<vertex;j++)
    {
        adj1[i][j]=adj[j][i];
    }
    }

this->adj=adj1;
}


void graph::dfs_t(int s)
{
    cout<<s<<" ";
    visited[s]=1;
    ftime[s]=INT_MIN;
    for(int i=0;i<this->vertex;i++)
        if(this->adj[s][i]==1&&!(visited[i]==1))
        {
            dfs_t(i);
        }

}
void graph::dfs(int s)
{   static int time=0;
    visited[s]=1;
    for(int i=0;i<this->vertex;i++)
        if(this->adj[s][i]==1&&!(visited[i]==1))
        {
            dfs(i);
        }
    ftime[s]=time++;

}

int main()
{
     graph g(5);
    g.add_edge(1, 0);
    g.add_edge(0, 2);
    g.add_edge(2, 1);
    g.add_edge(0, 3);
    g.add_edge(3, 4);

    cout << "Following are strongly connected components in "
            "given graph \n";
    g.scc();

}
