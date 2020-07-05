#include<bits/stdc++.h>
using namespace std;
void permute(int a[],int n)
{
    sort(a,a+n);
    do
    {
        for(int i = 0; i < n; ++i)
        {
            cout<<a[i];
        }
        cout<<" ";
    }while(next_permutation(a,a+n));
}
int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        permute(a,n);
    }
}
