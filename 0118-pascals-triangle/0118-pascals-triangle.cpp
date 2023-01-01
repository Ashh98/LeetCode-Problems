class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        else if (numRows == 2) return {{1}, {1,1}};
        else {
            vector<vector<int>> triangle = {{1}, {1,1}};
            int c = numRows - 2;
            while (c > 0) {
                vector<int> ele = triangle[triangle.size()-1];
                vector<int> tmp(ele.size()+1);
                
                    
                tmp[0] = ele[0]; tmp[tmp.size()-1] = ele[ele.size()-1];
                for (int i = 0; i < ele.size()-1; i++) {
                    tmp[i+1] = ele[i] + ele[i+1];
                }
                triangle.push_back(tmp);
                tmp.clear(); ele.clear();
                c--;
            }
            return triangle;
        }
    }
};