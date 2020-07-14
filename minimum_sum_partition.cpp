#include<bits/stdc++.h>
using namespace std;
long int minsubset(long int a[], long int n, long int sum)
{
    long int dp[n+1][sum+1],min,m;
    for(int i = 0; i <= n; ++i)
        dp[i][0] = 1;
    for(int i = 1; i <= sum; ++i)
        dp[0][i] = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= sum; ++j)
        {
            if(a[i-1] <= j)
                dp[i][j] = max(dp[i-1][j-a[i-1]],dp[i-1][j]);
            else if(a[i-1] > j)
                dp[i][j] = dp[i-1][j];
        }
    }
    min = INT_MAX;
    for(int i = 0; i <= sum/2; ++i)
    {
        if(dp[n][i])
        {
            m = sum - 2*i;
            if(min > m)
                min = m;
        }
    }
    return min;
}
int main()
{
    long int t,n,sum,res;
    cin >> t;
    while(t--)
    {
        cin >> n;
        long int a[n],sum = 0;
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];
        }
        res = minsubset(a,n,sum);
        cout<<res<<"\n";
    }
}

