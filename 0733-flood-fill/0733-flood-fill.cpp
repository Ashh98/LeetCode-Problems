class Solution {
public:
    int width, height;
    vector<vector<int>> image;
    
    bool isInside(int row, int col) {
        return (0 <= row && row < height) && (0 <= col && col < width);
    }
    
    void dfs(vector<vector<int>>& image, int row, int col, int color, int curr_color) {
        image[row][col] = color;
        if (isInside(row+1, col) ){
            if (image[row+1][col] == curr_color) dfs(image, row+1, col, color, curr_color);
        } 
        if (isInside(row, col+1)) {
            if (image[row][col+1] == curr_color) dfs(image, row, col+1, color, curr_color);
        } 
        if (isInside(row-1, col) ) {
            if (image[row-1][col] == curr_color) dfs(image, row-1, col, color, curr_color);
        } 
        if (isInside(row, col-1)) {
            if (image[row][col-1] == curr_color) dfs(image, row, col-1, color, curr_color);
        } 
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& _image, int sr, int sc, int color) {
        image = _image;
        height = image.size();
        width = image[0].size();
        
        if (image[sr][sc] == color) return image;
        else dfs(image, sr, sc, color, image[sr][sc]);
        
        return image;
    }
};