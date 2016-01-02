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
    int c_util(int,int[]);
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
}


void graph::has_cycle()
{

    int * visited=new int [vertex];
    fill(visited,visited+vertex,0);

    int r=0;
    for(int i=0;i<vertex;i++)
    {
        if(visited[i]==0)
            r=c_util(i,visited);

    }


    if(r==1)
        cout<<" CYCLE"<<endl;
    else
        cout<<"NO CYCLE"<<endl;



}


int graph::c_util(int s,int visited[])
{
    visited[s]=1;
    cout<<"source as "<<s<<endl;

    for(int i=0;i<vertex;i++)
    {
      if(adj[s][i]==1)
        {


            if(visited[i]==0)
            {
                cout<<"visiting "<<i<<endl;
               if(c_util(i,visited))
                    {   cout<<"detected "<<i<<endl;
                        return 1;

                    }
            }
            else if(visited[i]==1)
            {   cout<<"backedge form "<<s<<"to  "<<i<<endl;
                return 1;
            }
            else
            cout<<"visiting "<<i<<"failed"<<endl;
        }
    }
    visited[s]=2;

      return 0;

}







int main()
{


    graph g1(3);
    g1.add_edge(0, 1);
    g1.add_edge(1, 2);
    g1.add_edge(2,0);


    g1.has_cycle();



}
