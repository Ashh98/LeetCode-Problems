class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        if (rowIndex == 0) return {1};
        else if (rowIndex == 1) return {1,1};
        
        vector<int> dp = {1,1};
        int cnt = 0; int prev, prevN;
        while (cnt <= rowIndex-2) {
            dp.push_back(1);
            for (int i = 1; i < dp.size()-1; i++) {
                if (i==1) {
                    prev = dp[i];
                    dp[i] = dp[i]+dp[i-1];
                } else {
                    prevN = dp[i];
                    dp[i] = dp[i]+prev;
                    prev=prevN;
                }
            }
            cnt++;
        }
        return dp;
    }
};