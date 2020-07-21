class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();  
        vector <int> arr(n,INT_MAX);
        arr[0] = 0;
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(i <= j + nums[j])
                    arr[i] = min(arr[i],arr[j]+1);
            }
        }
        return arr[n-1];
    }
};
