#include<bits/stdc++.h>
#define V 4
using namespace std;
void floydWarshall(int graph[V][V])
{
    for(int k = 0; k < V; ++k)
    {
        for(int i = 0; i < V; ++i)
        {
            for(int j = 0; j < V; ++j)
            {
                if(graph[i][k] == INT_MAX || graph[k][j] == INT_MAX)
                    continue;
                else if((graph[i][k]+graph[k][j]) < graph[i][j])
                    graph[i][j] = graph[i][k]+graph[k][j];
            }
        }
    }
    for(int i = 0; i < V; ++i)
    {
        if(graph[i][i] < 0)
            cout<<"Negative edge cycle is present\n";
    }
    for(int i = 0; i < V; ++i)
    {
        for(int j = 0; j < V; ++j)
        {
            cout<<i<<" to "<<j<<" distance is "<<graph[i][j]<<"\n";
        }
        cout<<"\n";
    }
}
int main()
{
    int E,src,dest,wt,k,u,v;
    cin >> E;
    vector<pair<pair<int,int>,int>> adj;
    for(int i = 0; i < E; ++i)
    {
        cin >> src >> dest >> wt;
        adj.push_back({{src,dest},wt});
    }
    int graph[V][V];
    k = 0;
    for(int i = 0; i < V; ++i)
    {
        for(int j = 0; j < V; ++j)
        {
            if(i == j)
                graph[i][j] = 0;
            else
            {
                u = adj[k].first.first, v = adj[k].first.second;
                if(u == i && v == j)
                {
                    graph[i][j] = adj[k].second;
                    k++;
                }
                else
                    graph[i][j] = INT_MAX;
            }
        }
    }
    floydWarshall(graph);
}
