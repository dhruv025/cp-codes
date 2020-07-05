#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,sq;
    cin >> t;
    while(t--)
    {
        cin >> n;
        sq = sqrt(n);
        bool prime[n+1];
        memset(prime,true,sizeof(prime));
        prime[0] = prime[1] = false;
        for(int p = 2; p <= sq; ++p)
        {
            if(prime[p])
            {
                for(int i = p*p; i < n; i += p)
                {
                    prime[i] = false;
                }
            }
        }
        for(int i = 0; i <= n; ++i)
        {
            if(prime[i])
                cout<<i<<" ";
        }
        cout<<"\n";
    }
}
