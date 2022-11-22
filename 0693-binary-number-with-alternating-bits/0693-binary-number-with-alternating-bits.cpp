class Solution {
public:
    bool hasAlternatingBits(int n) {
        int tmp = n; tmp >>= 1;
        while (n) {
            if (n%2 == tmp%2) return false;
            n >>= 1; tmp >>= 1;
        }
        return true;
    }
};