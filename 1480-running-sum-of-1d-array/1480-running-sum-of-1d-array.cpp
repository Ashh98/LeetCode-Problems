class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sums;
        int c = 0;
        for (int i = 0; i < nums.size(); i++) {
            c = c + nums[i];
            sums.push_back(c);
        }
        return sums;
    }
};