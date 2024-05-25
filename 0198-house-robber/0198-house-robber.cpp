class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);
        int maxi = INT_MIN;

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            if (dp[i-2] > maxi) maxi = dp[i-2];
            dp[i] = nums[i] + maxi;
        }
        
        maxi = INT_MIN;
        for (auto& i : dp) {
            if (i > maxi) maxi = i;
        }
        
        return maxi;
    }
};