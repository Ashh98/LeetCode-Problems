class Solution {
public:
    int height, width;
    vector<vector<int>> grid;

    bool isInside(int x, int y) {
        return (0 <= x && x < height) && (0 <= y && y < width);
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int& currArea) {
        if (isInside(i-1, j)) {
            if (grid[i-1][j] == 1) {
                grid[i-1][j] = 0;
                currArea++;
                dfs(grid, i-1, j, currArea);
            }
        }
        if (isInside(i+1, j)) {
            if (grid[i+1][j] == 1) {
                grid[i+1][j] = 0;
                currArea++;
                dfs(grid, i+1, j, currArea);
            }
        }
        if (isInside(i, j+1)) {
            if (grid[i][j+1] == 1) {
                grid[i][j+1] = 0;
                currArea++;
                dfs(grid, i, j+1, currArea);
            }
        }
        if (isInside(i, j-1)) {
            if (grid[i][j-1] == 1) {
                grid[i][j-1] = 0;
                currArea++;
                dfs(grid, i, j-1, currArea);
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& _grid) {
        grid = _grid;
        height = grid.size(), width = grid[0].size();
        int maxArea = 0, currArea = 1;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == 1) {
                    currArea = 1;
                    grid[i][j] = 0;
                    dfs(grid, i, j, currArea);
                    if (currArea > maxArea) maxArea = currArea;
                } 
            }
        }
        return maxArea;
    }
};