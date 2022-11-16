class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c = 0;
        
        while (n) {
            if (n % 2 == 1) c++;
            n >>= 1;
        }
        return c;
    }
};