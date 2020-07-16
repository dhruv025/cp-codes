class Solution {
public:
    string reverseWords(string s) 
    {
        int len = s.length();
        if(len == 0)
            return "";
        vector <string> res;
        string str;
        if(s[0] == ' ')
            str = "";
        else
            str = str + s[0];
        for(int i = 1; s[i] != '\0'; ++i)
        {
            if(s[i] != ' ')
            {
                str = str + s[i];
                continue;
            }
            else if(s[i-1] != ' ')
            {
                res.push_back(str);
                str = "";
            }
        }
        res.push_back(str);
        int n = res.size();
        if(n == 1)
            return res[0];
        string result;
        if(int(res[n-1][0]) == 0)
            result = "";
        else
        {
            result = result + res[n-1];
            result = result + " ";
        }
        for(int i = n-2; i >= 0; --i)
        {
            
            result = result + res[i];
            if(i > 0)
                result = result + " ";
        }
        return result;
    }
};
