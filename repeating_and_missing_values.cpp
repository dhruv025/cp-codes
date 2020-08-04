vector<int> Solution::repeatedNumber(const vector<int> &A) 
{
    int n = A.size(),xor1 = A[0],set_bit,x = 0, y = 0,repeating,missing;
    for(int i = 1; i < n; ++i)
    {
        xor1 = xor1 ^ A[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        xor1 = xor1 ^ i;
    }
    set_bit = xor1 & ~(xor1 - 1);
    for(int i = 0; i < n; ++i)
    {
        if(A[i] & set_bit)
            x = x ^ A[i];
        else
            y = y ^ A[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        if(i & set_bit)
            x = x ^ i;
        else
            y = y ^ i;
    }
    for(int i = 0; i < n; ++i)
    {
        if(A[i] == x)
        {
            repeating = x;
            missing = y;
            break;
        }
        if(A[i] == y)
        {
            repeating = y;
            missing = x;
            break;
        }
    }
    return {repeating,missing};
}
