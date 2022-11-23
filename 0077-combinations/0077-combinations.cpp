class Solution {
public:
    void combine(int n, int k, int ind, vector<int>& tmp, vector<vector<int>>& res) {
        if (k > 0) {
            while (ind <= n) {
                tmp.push_back(ind);
                combine(n, k-1, ind+1, tmp, res);
                tmp.pop_back();
                ind++;
            }
        } else res.push_back(tmp);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp = {};
        combine(n, k, 1, tmp, res);
        return res;
    }
};