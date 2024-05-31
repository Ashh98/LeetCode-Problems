class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int min_sum = INT_MAX;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (i != 0) {
                    if (j == 0) {
                        matrix[i][j] = matrix[i][j] + min(matrix[i-1][j], matrix[i-1][j+1]);
                    } else if (j == matrix[0].size()-1) {
                        matrix[i][j] = matrix[i][j] + min(matrix[i-1][j], matrix[i-1][j-1]);
                    } else {
                        matrix[i][j] = matrix[i][j] + min(min(matrix[i-1][j], matrix[i-1][j-1]), matrix[i-1][j+1]);
                    }
                }
                
                if (i == matrix.size()-1) {
                    if (matrix[i][j] < min_sum) min_sum = matrix[i][j];
                }
            }
        }
        
        return min_sum;
    }
};