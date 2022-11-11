class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        
        for (int i = 1; i < nums.size(); i=i+2) {
            sum = sum + min(nums[i-1], nums[i]);
        }
        return sum;
    }
};