class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int numSize = nums.size();
        vector<int> ans(numSize, 0);
        for (int i = 0; i < numSize; i++) ans[i] = nums[nums[i]];
        return ans;
    }
};