#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(vector<int>& nums) 
    {
        int n = nums.size(),count,m,mod,p,res = 0;
        vector <int> bits;
        for(int i = 0; i < 32; ++i)
        {
            count = 0;
            m = 1 << i;
            for(int j = 0; j < n; ++j)
            {
                if(m&nums[j])
                    count++;
            }
            mod = count % 3;
            bits.push_back(mod);
        }
        for(int i = 0; i < 32; ++i)
        {
            p = 1 << i;
            res = res + (p*bits[i]);
        }
        return res;
    }
};
