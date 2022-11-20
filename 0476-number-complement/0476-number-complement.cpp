class Solution {
public:
    int findComplement(int num) {
        long m = 1; int res = 0;
        while (num) {
            if (!(num%2)) res += m;
            num >>= 1;
            m *= 2;
        }
        return res;
    }
};