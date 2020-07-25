class Solution {
public:
    bool isValid(string s) 
    {
        int len = s.length();
        if(len == 1)
            return false;
        stack <char> stk;
        for(int i = 0; i < len; ++i)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                stk.push(s[i]);
            else if(!stk.empty())
            {
                if((stk.top() == '(' && s[i] == ')') || (stk.top() == '{' && s[i] == '}')
                    || (stk.top() == '[' && s[i] == ']') )
                    stk.pop();
                else
                    return false;
            }
            else
                stk.push(s[i]);
        }
        if(stk.empty())
            return true;
        else
            return false;
    }
};
