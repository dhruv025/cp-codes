#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[], vector<bool> &visited, stack<int> &stk, int source)
{
    for(auto x : adj[source])
    {
        if(visited[x] == false)
        {
            visited[x] = true;
            dfs(adj,visited,stk,x);
        }
    }
    stk.push(source);
}
int main()
{
    int V,E,src,dest;
    cin >> V >> E;
    vector<int> adj[V];
    for(int i = 0; i < E; ++i)
    {
        cin >> src >> dest;
        adj[src].push_back(dest);
    }
    vector<int> res;
    stack<int> stk;
    vector<bool> visited(V,false);
    for(int i = 0; i < V; ++i)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            dfs(adj,visited,stk,i);
        }
    }
    while(!stk.empty())
    {
        res.push_back(stk.top());
        stk.pop();
    }
    for(int i = 0; i < V; ++i)
        cout<<res[i]<<" ";
}
