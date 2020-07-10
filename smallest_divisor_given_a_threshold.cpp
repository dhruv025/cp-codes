class Solution {
public:
    int check(vector<int>& nums, int mid, int n)
    {
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            res += ceil((float)nums[i]/mid);
        }
        return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int n = nums.size(), lb = 1, ub = INT_MIN,mid,res,ans = 0;
        for(int i = 0; i < n; ++i)
        {
            if(ub < nums[i])
                ub = nums[i];
        }
        while(lb <= ub)
        {
            mid = lb-(lb-ub)/2;
            res = check(nums,mid,n);
            if(res > threshold)
                lb = mid + 1;
            else
            {
                ans = mid;
                ub = mid - 1;
            }
        }
        return ans;
    }
};
