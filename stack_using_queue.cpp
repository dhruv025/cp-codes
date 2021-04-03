#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n;
    vector<string> str;
    for(int i = 0; i < n; ++i)
    {
        cin >> s;
        str.push_back(s);
    }
    queue<string> q1,q2;
    for(int i = 0; i < n; ++i)
    {
        if(str[i] != "p")
        {
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(str[i]);
            while(!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
        else
        {
            if(q1.empty())
                cout<<"Underflow Condition"<<" ";
            else
            {
                cout<<q1.front()<<" ";
                q1.pop();
            }
        }
    }
}
