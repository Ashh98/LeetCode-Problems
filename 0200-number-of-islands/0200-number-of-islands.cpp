class Solution {
public:
    int height, width;
    vector<vector<char>> grid;

    bool isInside(int x, int y) {
        return (0 <= x && x < height) && (0 <= y && y < width);
    }
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (isInside(i-1, j)) {
            if (grid[i-1][j] == '1') {
                grid[i-1][j] = '0';
                dfs(grid, i-1, j);
            }
        }
        if (isInside(i+1, j)) {
            if (grid[i+1][j] == '1') {
                grid[i+1][j] = '0';
                dfs(grid, i+1, j);
            }
        }
        if (isInside(i, j+1)) {
            if (grid[i][j+1] == '1') {
                grid[i][j+1] = '0';
                dfs(grid, i, j+1);
            }
        }
        if (isInside(i, j-1)) {
            if (grid[i][j-1] == '1') {
                grid[i][j-1] = '0';
                dfs(grid, i, j-1);
            }
        }
    }

    int numIslands(vector<vector<char>>& _grid) {
        grid = _grid;
        height = grid.size(), width = grid[0].size();
        int count = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    dfs(grid, i, j);
                    count++;
                } 
            }
        }
        return count;
    }
};