class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, 0);
        dp[0] = cost[0]; dp[1] = cost[1];
        for (int i = 2; i < dp.size(); i++) {
            if (i == dp.size()-1) return min(dp[i-1], dp[i-2]);
            else {
                dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
            }
        }
        return 0;
    }
};