#include<iostream>
#include<algorithm>
using namespace std;
bool compare(pair <int,int>a, pair <int,int>b)
{
    return a.second < b.second;
}
int actselect(vector<pair<int,int>> activities, int n)
{
    sort(activities.begin(),activities.end(),compare);
    int end = activities[0].second, count = 1;
    for(int i = 1; i < n; ++i)
    {
        if(end <= activities[i].first)
        {
            count++;
            end = activities[i].second;
        }
    }
    return count;
}
int main()
{
    int t,n,start,end,activity;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector <pair<int,int> > activities;
        for(int i = 0; i < n; ++i)
        {
            cin >> start >> end;
            activities.push_back({start,end});
        }
        activity = actselect(activities,n);
        cout<<activity<<"\n";
    }
}
