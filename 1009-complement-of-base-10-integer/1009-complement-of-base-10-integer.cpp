class Solution {
public:
    int bitwiseComplement(int n) {
        int mult = 1; int res = 0;
        if (n == 0) return 1;
        
        while (n) {
            if (!(n%2)) res += mult;
            mult *= 2;
            n >>= 1;
        }
        return res;
    }
};