#include<bits/stdc++.h>
using namespace std;
bool compare(pair <int,int> a, pair <int,int> b)
{
    return a.second > b.second;
}
int jobsequence(vector <pair <int,int>> job, int n)
{
    int jobs_assigned = 0,profit = 0,i,j,max_deadline = INT_MIN;
    for(int i = 0; i < n; ++i)
        max_deadline = max(max_deadline,job[i].first);
    sort(job.begin(),job.end(),compare);
    bool assigned[max_deadline];
    memset(assigned,false,sizeof(assigned));
    for(i = 0; i < n; ++i)
    {
        for(j = job[i].first-1; j >= 0; --j)
        {
            if(assigned[j] == false)
            {
                profit += job[i].second;
                jobs_assigned++;
                assigned[j] = true;
                break;
            }
        }
    }
    cout<<jobs_assigned<<" ";
    return profit;
}
int main()
{
    int t,n,id,deadline,profit,max_profit;
    cin >> t;
    while(t--)
    {
        vector <pair <int,int>> job;
        cin >> n;
        for(int i = 0; i < n; ++i)
        {
            cin >> id >> deadline >> profit;
            job.push_back({deadline,profit});
        }
        max_profit = jobsequence(job,n);
        cout<<max_profit<<"\n";
    }
}
