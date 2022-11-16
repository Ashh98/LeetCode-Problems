class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> ump;
        
        for (int i = 0; i < nums.size(); i++) {
            if (ump.find(nums[i]) != ump.end()) {
                ump[nums[i]]++;
                if (ump[nums[i]] > nums.size()/2) return nums[i];
            } else ump.insert({nums[i], 1});
        }
        
        return nums[0];
    }
};