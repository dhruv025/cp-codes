#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,max;
    cin >> t;
    while(t--)
    {
        max = INT_MIN;
        cin >> n;
        int arr[n],lis[n];
        for(int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        lis[0] = 1;
        for(int i = 1; i < n; ++i)
        {
            lis[i] = 1;
            for(int j = 0; j < i; ++j)
            {
                if(arr[i] > arr[j] && lis[i] <= lis[j])
                    lis[i] = lis[j] + 1;
            }
        }
        for(int i = 0; i < n; ++i)
        {
            if(max < lis[i])
                max = lis[i];
        }
        cout<<max<<"\n";
    }
}
