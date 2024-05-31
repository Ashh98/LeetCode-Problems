class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size()+2, vector<int>(matrix[0].size()+2, 0));
        int max_side = 0;
        
        for (int i = 1; i < dp.size()-1; i++) {
            for (int j = 1; j < dp[0].size()-1; j++) {
                if (matrix[i-1][j-1] == '1') dp[i][j] = 1;
                else if (matrix[i-1][j-1] == '0') dp[i][j] = 0;
            }
        }
        
        for (int i = 1; i < dp.size()-1; i++) {
            for (int j = 1; j < dp[0].size()-1; j++) {
                if (dp[i][j] == 1) {
                    dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1])+1;
                    if (dp[i][j] > max_side) max_side = dp[i][j];
                }
            }
        }
        
        return max_side*max_side;
    }
};