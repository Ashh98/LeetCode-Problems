class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        long x = pow(2,31);
        for (int i = 31; i >= 0; i--) {
            res = res + x * (n%2);
            x /= 2;
            n >>= 1;
        }
        return res;
    }
};