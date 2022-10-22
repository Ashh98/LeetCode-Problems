class Solution {
public:
    bool isPowerOfFour(int n) {
        float pwr = (log(n)/log(4));
        if (n == 0) {
            return false;
        } else {
            if (pwr == floor(pwr)) {
                return true;
            } else {
                return false;
            }
        }
    }
};