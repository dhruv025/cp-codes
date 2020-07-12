class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t rev = 0, bits = 31;
        while(n != 0)
        {
            rev += (n&1) << bits;
            n = n >> 1;
            bits -= 1;
        }
        return rev;
    }
};
