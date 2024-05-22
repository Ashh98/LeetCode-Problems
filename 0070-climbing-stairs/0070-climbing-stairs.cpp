class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1, c;
        if (n == 1) return b;
        
        for (int i = 2; i <= n; i++) {
            c = a+b;
            a = b; b = c;
        }
        
        return c;
    }
};