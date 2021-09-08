class Solution {
public:
    void generateParenthesis(int n, int o, int c, string str,vector<string> &res)
    {
        if(c == n)
        {
            res.push_back(str);
            return;
        }
        if(o > c)
            generateParenthesis(n,o,c+1,str+")",res);
        if(o < n)
            generateParenthesis(n,o+1,c,str+"(",res);
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        generateParenthesis(n,0,0,"",res);
        return res;
    }
};
