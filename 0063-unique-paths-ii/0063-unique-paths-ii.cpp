class Solution {
public:
    long uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        vector<vector<long>> dp(obstacleGrid.size()+2, vector<long>(obstacleGrid[0].size()+2, 0));
        dp[1][1]=2;
        
        for (int i = 1; i < dp.size()-1; i++) {
            for (int j = 1; j < dp[0].size()-1; j++) {
                if (i == 1 && j == 1) continue;
                dp[i][j] = obstacleGrid[i-1][j-1];
            }
        }
        
        for (int i = 1; i < dp.size()-1; i++) {
            for (int j = 1; j < dp[0].size()-1; j++) {
                if (dp[i][j] == 1) {
                    continue;
                } else if (dp[i-1][j] == 1) {
                    if (dp[i][j-1] != 1) dp[i][j]+=dp[i][j-1];
                } else if (dp[i][j-1] == 1) {
                    if (dp[i-1][j] != 1) dp[i][j]+=dp[i-1][j];
                } else {
                    dp[i][j]+=(dp[i-1][j]+dp[i][j-1]);
                }
            }
        }
     
        return dp[dp.size()-2][dp[0].size()-2]/2;
    }
};