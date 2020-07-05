#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int t,n,c;
    cin >> t;
    while(t--)
    {
        stack <int> stk;
        cin >> n;
        long int a[n],res[n];
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        for(int i = n-1; i >= 0; --i)
        {
            while(!stk.empty() && stk.top() <= a[i])
                stk.pop();
            if(stk.empty())
                res[i] = -1;
            else
                res[i] = stk.top();
            stk.push(a[i]);
        }
        for(int i = 0; i < n; ++i)
            cout<<res[i]<<" ";
        cout<<"\n";
    }
}
