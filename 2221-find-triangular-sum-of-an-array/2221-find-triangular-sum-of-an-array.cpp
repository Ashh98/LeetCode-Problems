class Solution {
public:
    int res = 0;
    int triangularSum(vector<int>& nums) {
        int arrSize = nums.size();
        if (arrSize == 1) {
            res = nums[0];
        } else {
            for (int i = 0; i < arrSize - 1; i++) {
                nums.push_back((nums[i]+nums[i+1])%10);
            }
            reverse(nums.begin(), nums.end());
            for (int i = nums.size()-1; i >= nums.size()-arrSize; i--) {
                nums.pop_back();
            }
            reverse(nums.begin(), nums.end());
            triangularSum(nums);
        }
        return res;
    }
};