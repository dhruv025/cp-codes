class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int size = 1, n = nums.size(), val;
        if(n == 0)
            return 0;
        val = nums[0];
        for(int i = 0; i < n; ++i)
        {
            if(val == nums[i])
                continue;
            else
            {
                nums[size] = nums[i];
                size++;
                val = nums[i];
            }
        }
        return size;
    }
};
