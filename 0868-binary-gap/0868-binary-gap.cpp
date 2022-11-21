class Solution {
public:
    int binaryGap(int n) {
        int max = 0; int c = 0;
        while (n) {
            if (n%2) {
                if (c == 0) c++;
                else {
                    if (c > max) max = c;
                    c = 1;
                }
            } else {
                if (c > 0) c++;
            }
            n >>= 1;
        }
        return max;
    }
};