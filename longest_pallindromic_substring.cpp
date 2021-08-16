class Solution {
public:
    string expand(string s, int i, int j)
    {
        int n = s.length(), count = 0;
        if(i == j)
        {
            count++;
            i--;
            j++;
        }
        while(i >= 0 && j < n && s[i] == s[j])
        {
            count += 2;
            i--;
            j++;
        }
        i = i+1;
        j = j-1;
        return s.substr(i,j-i+1);
    }
    string longestPalindrome(string s) 
    {
        int n = s.length(), l1, l2, max = 0;
        string s1,s2,res;
        for(int i = 0; i < n; ++i)
        {
            s1 = expand(s,i,i);
            l1 = s1.length();
            if(l1 > max)
            {
                max = l1;
                res = s1;
            }
            if(i < n-1)
            {
                s2 = expand(s,i,i+1);
                l2 = s2.length();
                if(l2 > max)
                {
                    max = l2;
                    res = s2;
                }
            }
        }
        return res;
    }
};
