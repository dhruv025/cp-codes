class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        string str = "";
        stack <char> stk;
        int len = num.length();
        for(int i = 0; i < len; ++i)
        {
            while(!stk.empty() && k > 0 && stk.top() > num[i])
            {
                stk.pop();
                k--;
            }
            if(!stk.empty() || num[i] != '0')
                stk.push(num[i]);
        }
        while(!stk.empty() && k--)
            stk.pop();
        if(stk.empty())
            return "0";
        while(!stk.empty())
        {
            str = str + stk.top();
            stk.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
