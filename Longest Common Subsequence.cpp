#include<iostream>
#include<vector>
using namespace std;
int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}
int longestcommon(string s1, string s2, int l1, int l2)
{
    int dp[l1+1][l2+1];
    for(int i = 0; i <= l1; ++i)
    {
        for(int j = 0; j <= l2; ++j)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for(int i = 1; i <= l1; ++i)
    {
        for(int j = 1; j <= l2; ++j)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    vector <char> v;
    int i = l1, j = l2,sz;
    string s = "";
    while(i > 0 && j > 0)
    {
        if(s1[i-1] == s2[j-1])
        {
            v.push_back(s1[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i][j-1] > dp[i-1][j])
                j--;
            else
                i--;
        }
    }
    sz = v.size();
    for(int i = sz-1; i >= 0; --i)
        s = s + v[i];
    cout<<"Longest Common Subsequence is "<<s<<" ";
    return dp[l1][l2];
}
int main()
{
    string s1,s2;
    int l1,l2,len;
    cout<<"Enter sequence 1 : ";
    cin >> s1;
    cout<<"Enter sequence 2 : ";
    cin >> s2;
    l1 = s1.length();
    l2 = s2.length();
    len = longestcommon(s1,s2,l1,l2);
    cout<<"of length "<<len;
}
