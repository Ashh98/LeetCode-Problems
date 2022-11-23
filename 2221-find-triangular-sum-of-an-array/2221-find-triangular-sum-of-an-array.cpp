class Solution {
public:
    int res = 0;
    int triangularSum(vector<int>& nums) {
        vector<int> tmp;
        if (nums.size() == 1) {
            res = nums[0];
        } else {
            for (int i = 0; i < nums.size()-1; i++) {
                tmp.push_back((nums[i]+nums[i+1])%10);
            }
            nums = tmp;
            triangularSum(nums);
        }
        return res;
    }
};