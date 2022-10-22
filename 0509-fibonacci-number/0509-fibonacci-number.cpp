class Solution {
public:
    int fib(int n) {
        int t0 = 0;
        int t1 = 1;
        int tn = 0;
        for (int i = 2; i <= n; i++) {
            tn = t0 + t1;
            t0 = t1;
            t1 = tn;
        }
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            return tn;
        }
    }
};