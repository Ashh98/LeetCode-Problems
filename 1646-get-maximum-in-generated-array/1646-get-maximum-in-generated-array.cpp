class Solution {
public:
    int getMaximumGenerated(int n) {
        
        if (n==0) return 0;
        else if (n==1) return 1;
        
        int max = INT_MIN;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        
        for (int i = 2; i < dp.size(); i++) {
            if (!(i%2)) dp[i] = dp[i/2];
            else dp[i] = dp[(i/2)+1] + dp[i/2];
            if (max < dp[i]) max=dp[i];
        }
        
        return max;
    }
};