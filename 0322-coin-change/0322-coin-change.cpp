class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        
        dp[0] = 0;
        
        for (int i = 1; i < dp.size(); i++) {
            for (auto& coin : coins) {
                int subp_amount = i-coin;
                if (subp_amount >= 0 && dp[subp_amount] != INT_MAX)
                    dp[i] = min(dp[i], dp[subp_amount]+1);
            }
        }
        
        return dp[amount] == INT_MAX? -1 : dp[amount];
    }
};