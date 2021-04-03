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
    for(int i = 0; i < n; ++i)
    {
        cout<<str[i]<<" ";
    }
    cout<<"\n";
    stack<string> stk1, stk2;
    stk1.push(str[0]);
    for(int i = 1; i < n; ++i)
    {
        if(str[i] != "d")
        {
            while(!stk1.empty())
            {
                stk2.push(stk1.top());
                stk1.pop();
            }
            stk1.push(str[i]);
            while(!stk2.empty())
            {
                stk1.push(stk2.top());
                stk2.pop();
            }
        }
        else
        {
            if(stk1.empty())
                cout<<"Queue is empty"<<" ";
            else
            {
                cout<<stk1.top()<<" ";
                stk1.pop();
            }
        }
    }
}
