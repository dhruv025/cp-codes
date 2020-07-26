class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        long int n = nums.size(),correctpos;
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] < 0)
                continue;
            correctpos = nums[i] - 1;
            while(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[correctpos])
            {
                swap(nums[i],nums[correctpos]);
                correctpos = nums[i] - 1;
            }
        }
        for(int i = 0; i < n; ++i)
        {
            if(i+1 != nums[i])
                return i+1;
        }
        return n+1;
    }
};
