class Solution {
public:
    vector<vector<int>> res;
    
    void combine(int n, int k, int ind, vector<int> tmp) {
        if (k > 0) {
            while (ind <= n) {
                tmp.push_back(ind);
                combine(n, k-1, ind+1, tmp);
                tmp.pop_back();
                ind++;
            }
        } else res.push_back(tmp);
    }
    
    vector<vector<int>> combine(int n, int k) {
        combine(n, k, 1, {});
        return res;
    }
};