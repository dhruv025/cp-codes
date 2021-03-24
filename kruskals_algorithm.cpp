#include<bits/stdc++.h>
using namespace std;
void printGraph(vector<pair<int,pair<int,int>> > adj)
{
    for(auto it : adj)
        cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<"\n";
}
int find(int x, int parent[])
{
    while(parent[x] != x)
    {
        x = parent[x];
    }
    return x;
}
void union_op(int x, int y, int parent[])
{
    int p = find(x,parent);
    int q = find(y,parent);
    parent[p] = q;
}
int kruskal(vector<pair<int,pair<int,int>> > adj, int parent[], int V)
{
    int u,v,wt,cost = 0,ctr = 0;
    for(auto it : adj)
    {
        u = it.second.first, v = it.second.second, wt = it.first;
        if(find(u,parent) != find(v,parent))
        {
            cost += wt;
            union_op(u,v,parent);
            printf("Edge %d : (%d, %d) cost : %d \n",ctr++, u, v, wt);
            if(ctr == V-1)
                break;
        }
    }
    return cost;
}
int main()
{
    int V,E,src,dest,wt,minCost;
    cin >> V >> E;
    int parent[V];
    for(int i = 0; i < V; ++i)
    {
        parent[i] = i;
    }
    vector<pair<int,pair<int,int>> > adj;
    for(int i = 0; i < E; ++i)
    {
        cin >> src >> dest >> wt;
        adj.push_back({wt,{src,dest}});
    }
    cout<<"\n";
    sort(adj.begin(),adj.end());
    printGraph(adj);
    cout<<"\n";
    minCost = kruskal(adj,parent,V);
    for(int i = 0; i < V; ++i)
    {
        cout<<parent[i]<<" ";
    }
    cout<<"\n";
    cout<<minCost;
}
