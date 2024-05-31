class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int min_sum = INT_MAX;
        for (int i = 0; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (i != 0) {
                    if (j == 0) {
                        triangle[i][j] = triangle[i][j] + triangle[i-1][j];
                    } else if (j == triangle[i].size()-1) {
                        triangle[i][j] = triangle[i][j] + triangle[i-1][j-1];
                    } else {
                        triangle[i][j] = triangle[i][j] + min(triangle[i-1][j], triangle[i-1][j-1]);
                    }
                }
                
                if (i == triangle.size()-1) {
                    if (triangle[i][j] < min_sum) min_sum = triangle[i][j];
                }
                
            }
            
        }
        
        return min_sum;
    }
};