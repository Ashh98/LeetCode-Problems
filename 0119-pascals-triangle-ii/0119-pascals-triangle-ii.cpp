class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        if (rowIndex == 0) return {1};
        else if (rowIndex == 1) return {1,1};
        
        vector<int> dp = {1,1};
        int cnt = 0;
        while (cnt <= rowIndex-2) {
            vector<int> dp_new(dp.size()+1, 0);
            dp_new[0] = 1, dp_new[dp.size()] = 1;
            for (int i = 1; i < dp_new.size()-1; i++) {
                dp_new[i] = dp[i]+dp[i-1];
            }

            dp=dp_new;
            cnt++;
        }
        return dp;
    }
};