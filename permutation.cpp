class Solution {
public:
    void permute(vector<int>& nums, int idx, vector<vector<int>>& res)
    {
        if(idx == nums.size())
        {
            res.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); ++i)
        {
            swap(nums[i],nums[idx]);
            permute(nums,idx+1,res);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        permute(nums,0,res);
        return res;
    }
};
