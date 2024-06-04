class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word2.size()+1, vector<int>(word1.size()+1, 0));
        for (int i = 0; i < word1.size(); i++) dp[0][i+1] = i+1;
        for (int i = 0; i < word2.size(); i++) dp[i+1][0] = i+1;
        
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                if (word1[j-1] == word2[i-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
                }
            }
        }
        
        return dp[dp.size()-1][dp[0].size()-1];
    }
};