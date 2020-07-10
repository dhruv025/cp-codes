class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int res1 = -1,res2 = -1;
        vector <int> res;
        int n = nums.size(), lb = 0, ub = n-1, mid;
        while(lb <= ub)
        {
            mid = lb-(lb-ub)/2;
            if(nums[mid] == target)
            {
                res1 = mid;
                ub = mid - 1;
            }
            else if(nums[mid] > target)
                ub = mid - 1;
            else
                lb = mid + 1;
        }
        res.push_back(res1);
        int start = 0, end = n-1;
        while(start <= end)
        {
            mid = start-(start-end)/2;
            if(nums[mid] == target)
            {
                res2 = mid;
                start = mid + 1;
            }
            else if(nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        res.push_back(res2);
        return res;
    }
};
