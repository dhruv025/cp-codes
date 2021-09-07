class Solution {
public:
    void solve(int idx, int target, vector<int> &arr, vector<vector<int>> &res, vector<int> &vec)
    {
        if(idx == arr.size())
        {
            if(target == 0)
                res.push_back(vec);
            return;
        }
        if(arr[idx] <= target)
        {
            vec.push_back(arr[idx]);
            solve(idx,target-arr[idx],arr,res,vec);
            vec.pop_back();
        }
        solve(idx+1,target,arr,res,vec);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int x) 
    {
        vector<vector<int> > res;
        vector<int> vec;
        solve(0,x,arr,res,vec);
        return res;
    }
};
