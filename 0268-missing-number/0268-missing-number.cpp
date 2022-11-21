class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> mask(nums.size()+1, 0);
        for (auto& i : nums) {
            mask[i]++;
        }
        
        for (int i = 0; i < mask.size(); i++) {
            if (mask[i] == 0) return i;
        }
        
        return -1;
    }
};