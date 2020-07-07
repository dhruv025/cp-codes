int maxLen(int A[], int n)
{
    //unordered map is used to store current sum and its index.
    unordered_map <int,int> mp;
    int sum = 0, max_len = 0;
    for(int i = 0; i < n; ++i)
    {
        sum = sum + A[i];
        if(A[i] == 0 && max_len == 0)
            max_len = 1;
        if(sum == 0)
            max_len = i+1;
	//checking if current element is present in map or not.
	//If yes, then update the value of max_len.
        if(mp.find(sum) != mp.end())
            max_len = max(max_len,i-mp[sum]);
        else
            mp[sum] = i;
    }
    return max_len;
}
