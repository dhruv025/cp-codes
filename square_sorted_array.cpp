class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n = nums.size(),i,j,k,n1,n2;
        vector<int> ans;
        if(n == 0)
            return ans;
        for(i = 0; i < n; ++i)
        {
            if(nums[i] >= 0)
                break;
        }
        j = i-1, n1 = 0, k = i, n2 = n;
        while(j >= n1 && k < n2)
        {
            if(nums[k] < abs(nums[j]))
            {
                ans.push_back(nums[k]*nums[k]);
                k++;
            }
            else
            {
                ans.push_back(nums[j]*nums[j]);
                j--;
            }
        }
        while(k < n2)
        {
            ans.push_back(nums[k]*nums[k]);
            k++;
        }
        while(j >= n1)
        {
            ans.push_back(nums[j]*nums[j]);
            j--;
        }
        return ans;
    }
};
