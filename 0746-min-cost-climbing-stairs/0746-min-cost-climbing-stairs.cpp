class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int k = 2, c = 0; int mini;
        vector<int> res(k, 0);
        for (int i = 0; i < res.size(); i++) {
            res[i] = cost[i];
        }
        for (int i = 2; i < cost.size(); i++) {
            c = cost[i]; mini = INT_MAX;
            for (int j = 0; j < res.size(); j++) {
                mini = min(mini, res[j]);
            }
            c += mini;
            for (int j = 0; j < res.size(); j++) {
                if (j == res.size()-1) res[j] = c;
                else res[j] = res[j+1];
            }
        }
        
        mini = INT_MAX;
        for (int i = 0; i < res.size(); i++) {
            mini = min(mini, res[i]);
        }
        return mini;
    }
};