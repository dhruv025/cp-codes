#include<bits/stdc++.h>
using namespace std;
int minVertex(vector<int> value, vector<bool> visited, int V)
{
    int min = INT_MAX, vertex;
    for(int i = 0; i < V; ++i)
    {
        if(visited[i] == false && min > value[i])
        {
            min = value[i];
            vertex = i;
        }
    }
    return vertex;
}
void dijkstra(vector<pair<int,int> > adj[], int V)
{
    vector<bool> visited(V,false);
    vector<int> value(V,INT_MAX);
    int parent[V],u,v,wt;
    value[0] = 0, parent[0] = -1;
    for(int i = 0; i < V-1; ++i)
    {
        u = minVertex(value,visited,V);
        visited[u] = true;
        for(auto it : adj[u])
        {
            v = it.first, wt = it.second;
            if(value[u] != INT_MAX && visited[v] == false && value[u]+wt < value[v])
            {
                value[v] = value[u]+wt;
                parent[v] = u;
            }
        }
    }
    for(int i = 1; i < V; ++i)
    {
        cout<<parent[i]<<"->"<<i<<" having weight : "<<value[i]<<"\n";
    }
}
int main()
{
    int V,E,src,dest,wt;
    cin >> V >> E;
    vector<pair<int,int> > adj[V];
    for(int i = 0; i < E; ++i)
    {
        cin >> src >> dest >> wt;
        adj[src].push_back({dest,wt});
        adj[dest].push_back({src,wt});
    }
    dijkstra(adj,V);
}
