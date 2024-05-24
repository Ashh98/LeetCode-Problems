class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mx(m+2, vector<int>(n+2, 0));
        mx[1][1] = 1;
        for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) 
                if (!(i == 1 && j == 1)) mx[i][j] = mx[i-1][j] + mx[i][j-1];
        
        return mx[m][n];
    }
};