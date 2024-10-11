class Solution {
public:
    unordered_map<int, int> memo;
    
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        
        if (memo.find(amount) != memo.end()) {
            return memo[amount];
        }
        
        int answer = INT_MAX;
        
        for (auto& coin : coins) {
            int subproblem = coinChange(coins, amount - coin);
            if (subproblem >= 0) { 
                answer = min(answer, subproblem + 1);
            }
        }
        
        memo[amount] = (answer == INT_MAX) ? -1 : answer;
        return memo[amount];
    }
};
