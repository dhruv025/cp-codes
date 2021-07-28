class Solution{
    public:
    int closest3Sum(int nums[], int n, int target)
    {
        // code here
        int j,k,sum,diff,min,res;
        sort(nums,nums+n);
        min = INT_MAX;
        for(int i = 0; i < n-2; ++i)
        {
            j = i+1, k = n-1;
            while(j < k)
            {
                sum = nums[i]+nums[j]+nums[k];
                diff = abs(target-sum);
                if(min > diff)
                {
                    min = diff;
                    res = sum;
                }
                if(target > sum)
                    j++;
                else if(target < sum)
                    k--;
                else
                {
                    k--;
                    j++;
                }
            }
        }
        return res;
    }
};
