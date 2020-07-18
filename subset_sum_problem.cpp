#include<iostream>
using namespace std;
bool subsetsum(int a[],int n,int sum)
{
    bool dp[n+1][sum+1];
    for(int i = 0; i <= n; ++i)
        dp[i][0] = true;
    for(int i = 1; i <= sum; ++i)
        dp[0][i] = false;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= sum; ++j)
        {
            if(a[i-1] <= j)
                dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    int t,n,sum;
    cin >> t;
    while(t--)
    {
        cin >> n >> sum;
        int a[n];
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        if(subsetsum(a,n,sum))
            cout<<"Yes"<<"\n";
        else
            cout<<"No"<<"\n";
    }
}
