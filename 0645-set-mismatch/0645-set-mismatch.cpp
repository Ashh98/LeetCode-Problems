class Solution {
public:
    int sumVec(vector<int>& vec) {
        int sum = 0;
        for (auto& i : vec) {
            sum += i;
        }
        return sum;
    }
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res = {0, 0}; int n = nums.size();
        int sum = sumVec(nums);
        for (auto& i : nums) {
            if (nums[abs(i)-1] < 0) {
                res[0] = abs(i);
                break;
            } else nums[abs(i)-1] = -nums[abs(i)-1];
        }
        res[1] = (n*(n+1)/2) - (sum - res[0]);
        return res;
    }
};