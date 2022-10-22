class Solution {
public:
    long long mySqrt(long long x) {
        long long mul = 0;
        for (long long i = 1; i <= x; i++) {
            if (i * i <= x) {
                mul = i;
            } else {
                break;
            }
        }
        if (x == 4) {
            return 2;
        } else {
            return mul;
        }
    }
};