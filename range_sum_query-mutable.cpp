class NumArray {
    int block_size;
    vector<int> arr;
    vector<int> blocks;
public:
    NumArray(vector<int>& nums) 
    {
        int n = nums.size();
        float sq = sqrt(n);
        block_size = ceil(sq);
        blocks.resize(block_size,0);
        arr.resize(n,0);
        for(int i = 0; i < n; ++i)
        {
            arr[i] = nums[i];
            blocks[i/block_size] += nums[i];
        }
    }
    
    void update(int i, int val) 
    {
        int old_value = arr[i];
        blocks[i/block_size] += (val - old_value);
        arr[i] = val;
    }
    
    int sumRange(int i, int j) 
    {
        int sum = 0, start = i/block_size, end = j/block_size,n,m;
        n = (start+1) * block_size, m = end * block_size;
        if(start == end)
        {
            while(i <= j)
                sum += arr[i++];
            return sum;
        }
        for(int p = i; p < n; ++p)
            sum += arr[p];
        for(int p = m; p < j+1; ++p)
            sum += arr[p];
        for(int p = start+1; p < end; ++p)
            sum += blocks[p];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
