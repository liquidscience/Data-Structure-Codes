#include<iostream>
#include<stack>
#include<limits.h>

using namespace std;

class graph
{
    int vertex;
    int **adj;

    public: graph(int v);
    void add_edge(int s,int d);
    public:void has_cycle();
    int c_util(int,int[],int[]);
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


}

void graph::add_edge(int s,int d)
{
    adj[s][d]=1;
    adj[d][s]=1;
}


void graph::has_cycle()
{   int * parent=new int[vertex];
    fill(parent,parent+vertex,-1);
    int * visited=new int [vertex];

    int r=0;
    for(int i=0;i<vertex;i++)
    {
        if(!(visited[i]==1))
            r=c_util(i,visited,parent);

    }


    if(r==1)
        cout<<" CYCLE"<<endl;
    else
        cout<<"NO CYCLE"<<endl;



}


int graph::c_util(int s,int visited[],int parent[])
{
    visited[s]=1;
    cout<<"source as "<<s<<endl;

    for(int i=0;i<vertex;i++)
    {
      if(adj[s][i]==1)
        {


            if(!(visited[i]==1))
            {   parent[i]=s;
                cout<<"visiting "<<i<<endl;
               if(c_util(i,visited,parent))
                    {   cout<<"detected "<<i<<endl;
                        return 1;

                    }
            }
            else if(parent[s]!=i)
            {   cout<<"backedge not parent  "<<i<<endl;
                return 1;
            }
            else
            cout<<"visiting "<<i<<"failed"<<endl;
        }
    }

      return 0;

}







int main()
{


    graph g1(3);
    g1.add_edge(1, 0);
    g1.add_edge(1, 2);


    g1.has_cycle();



}
