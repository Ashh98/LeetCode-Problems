class Solution {
public:
    long coinChange(vector<int>& coins, long amount) {
        vector<long> dp(amount+1, INT_MAX);
        dp[0] = 0;
        
        for (long i = 0; i < dp.size(); i++) {
            if (dp[i] == INT_MAX) continue;
            for (auto& coin : coins) {
                long fwd_subp_amount = i+coin;
                if (fwd_subp_amount <= amount) {
                    dp[fwd_subp_amount] = min(dp[fwd_subp_amount], dp[i]+1);
                }
            }
        }
        
        return dp[amount] == INT_MAX? -1 : dp[amount];
    }
};