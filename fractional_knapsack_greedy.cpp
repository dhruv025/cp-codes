#include<bits/stdc++.h>
using namespace std;
bool compare(pair <double, pair<int,int> > a, pair <double, pair<int,int> > b)
{
    return a.first > b.first;
}
double fractionalknap(vector <pair <double, pair<int,int>> > items, int W, int n)
{
    sort(items.begin(),items.end(),compare);
    double profit = 0;
    for(int i = 0; i < n; ++i)
    {
        if(items[i].second.second < W)
        {
            profit += items[i].second.first;
            W -= items[i].second.second;
        }
        else
        {
            profit += items[i].first * W;
            break;
        }
    }
    return profit;
}
int main()
{
    int t,n,W,values,weight;
    double profit,val_weight_ratio;
    cin >> t;
    while(t--)
    {
        vector <pair <double, pair<int,int>> > items;
        cin >> n >> W;
        for(int i = 0; i < n; ++i)
        {
            cin >> values >> weight;
            val_weight_ratio = double(values/((double)weight));
            items.push_back({val_weight_ratio,{values,weight}});
        }
        profit = fractionalknap(items,W,n);
        printf("%.2f\n",profit);
    }
}
