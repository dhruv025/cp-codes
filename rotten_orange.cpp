class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges.
    void solve(vector<vector<int>>& grid, pair<int,int> p, queue<pair<int,int>>& q, int n, int m)
    {
        int x,y,s,d;
        x = p.first, y = p.second;
        int rows[] = {0,-1,0,1}, cols[] = {-1,0,1,0};
        for(int k = 0; k < 4; ++k)
        {
            s = x+rows[k], d = y+cols[k];
            if(s >= 0 && s < n && d >= 0 && d < m && grid[s][d] == 1)
            {
                q.push({s,d});
                grid[s][d] = 2;
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size(), m = grid[0].size(), mintime = 0, sz;
        queue<pair<int,int>> q;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        while(!q.empty())
        {
            sz = q.size();
            for(int i = 0; i < sz; ++i)
            {
                pair<int,int> p = q.front();
                q.pop();
                solve(grid,p,q,n,m);
            }
            sz = q.size();
            if(sz > 0)
                mintime++;
        }
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return mintime;
    }
};
