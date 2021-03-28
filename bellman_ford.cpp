#include<bits/stdc++.h>
using namespace std;
void bellmonFord(vector<pair<pair<int,int>,int>> adj, int V, int E)
{
    int parent[V], cost[V];
    vector<int> value(V,INT_MAX);
    parent[0] = -1, cost[0] = 0, value[0] = 0;
    bool updated;
    for(int i = 0; i < V-1; ++i)
    {
        updated = false;
        for(int j = 0; j < E; ++j)
        {
            int u,v,wt;
            u = adj[j].first.first;
            v = adj[j].first.second;
            wt = adj[j].second;
            if(value[u] != INT_MAX && value[u]+wt < value[v])
            {
                value[v] = value[u]+wt;
                parent[v] = u;
                cost[v] = value[v];
                updated = true;
            }
        }
        if(updated == false)
            break;
    }
    for(int j = 0; j < E && updated == true; ++j)
    {
        int u,v,wt;
        u = adj[j].first.first;
        v = adj[j].first.second;
        wt = adj[j].second;
        if(value[u] != INT_MAX && value[u]+wt < value[v])
        {
            cout<<"Graph has -ve edge cycle\n";
        }
    }
    for(int i = 1; i < V; ++i)
    {
        cout<<"u->v: "<<parent[i]<<"->"<<i<<"  Cost to reach "<<i<<" from source 0 = "<<value[i]<<"\n";
    }
}
int main()
{
    int V,E,src,dest,wt;
    cin >> V >> E;
    vector<pair<pair<int,int>,int>> adj;
    for(int i = 0; i < E; ++i)
    {
        cin >> src >> dest >> wt;
        adj.push_back({{src,dest},wt});
    }
    bellmonFord(adj,V,E);
}
