class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int n = nums.size(), i = 0, j = n-1, k;
        while(i < j)
        {
            if(nums[i] != val && nums[j] == val)
            {
                i++;
                j--;
            }
            else if(nums[i] == val && nums[j] != val)
            {
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            else if(nums[i] != val && nums[j] != val)
                i++;
            else
                j--;
        }
        for(k = 0; k < n; ++k)
        {
            if(nums[k] == val)
                break;
        }
        return k;
    }
};
