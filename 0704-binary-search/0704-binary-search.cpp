class Solution {
public:
    
    void helper(vector<int>& nums, int target, int st, int end, int& result) {
        if (st <= end) {
            int mid = (st+end)/2;
            if (nums[mid] == target) result = mid;
            else {
                if (nums[mid] < target) helper(nums, target, mid+1, end, result);
                else helper(nums, target, st, mid-1, result);
            }
        }
    }
    
    int search(vector<int>& nums, int target) {
        int result = -1;
        helper(nums, target, 0, nums.size()-1, result);
        return result;
    }
};