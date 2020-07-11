class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int n = nums.size(), lb = 0, ub = n-1, mid;
        if(n == 1)
            return 0;
        while(lb <= ub)
        {
            mid = lb + ((ub-lb)/2);
            if(mid > 0 && mid < n-1)
            {
                 if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1])
                     return mid;
                else if(nums[mid-1] > nums[mid])
                    ub = mid - 1;
                else
                    lb = mid + 1;
            }
            else if(mid == 0)
            {
                if(nums[mid] > nums[mid+1])
                    return 0;
                else
                    return 1;
            }
            else if(mid == n-1)
            {
                if(nums[mid-1] > nums[mid-2])
                    return n-1;
                else
                    return n-2;
            }
        }
        return 0;
    }
};
