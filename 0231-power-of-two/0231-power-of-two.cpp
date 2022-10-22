class Solution {
public:
    bool dec;
    void isPowerOfTwoOP(double n) {
        if (n == 1.0) dec = true;
        else if (n == 0) dec = false;
        else if (floor(n) != n) dec = false;
        else isPowerOfTwoOP(n/2);
    }
    bool isPowerOfTwo(int n) { 
        isPowerOfTwoOP((double) n);
        return dec;
    }
};