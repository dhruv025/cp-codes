//complexity of this code -> n*logk
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() 
{
    int t,n,k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        priority_queue <int, vector<int>, greater<int> > q;
        vector <int> vec;
        int arr[n],d;
        for(int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        if(n != k)
        {
            for(int i = 0; i < n; ++i)
            {
                q.push(arr[i]);
                if(q.size() > k)
                {
                    vec.push_back(q.top());
                    q.pop();
                    d = i;
                    break;
                }
            }
            for(int j = d+1; j < n; ++j)
            {
                q.push(arr[j]);
                if(q.size() > k)
                {
                    vec.push_back(q.top());
                    q.pop();
                }
            }
            while(!q.empty())
            {
                vec.push_back(q.top());
                q.pop();
            }
            for(int i = 0; i < n; ++i)
            {
                cout<<vec[i]<<" ";
            }  
        }
        else
        {
            for(int i = 0; i < n; ++i)
            {
                q.push(arr[i]);
            }
            while(!q.empty())
            {
                cout<<q.top()<<" ";
                q.pop();
            }
        }
        cout<<"\n";
    }
}
