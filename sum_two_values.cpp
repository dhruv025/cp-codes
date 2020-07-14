#include<bits/stdc++.h>
using namespace std;
int main()
{
    map <int,int> mp;
    int n,x,temp;
    bool c = 0;
    cin >> n >> x;
    int a[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i)
    {
        temp = x - a[i];
        if(mp.find(temp) == mp.end())
            mp[a[i]] = i+1;
        else
        {
            c = 1;
            cout<<mp[temp]<<" "<<i+1;
            break;
        }
    }
    if(!c)
        cout<<"IMPOSSIBLE";
}
