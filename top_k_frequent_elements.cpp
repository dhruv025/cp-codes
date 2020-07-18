class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        int n = nums.size(); 
        priority_queue < pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > minh;
        unordered_map <int,int> mp;
        vector <int> res;
        for(int i = 0; i < n; ++i)
            mp[nums[i]] += 1;
        for(auto it : mp)
        {
            minh.push({(it).second,(it).first});
            if(minh.size() > k)
                minh.pop();
        }
        int sz = minh.size();
        for(int i = 0; i < sz; ++i)
        {
            res.push_back(minh.top().second);
            minh.pop();
        }
        return res;
    }
};
