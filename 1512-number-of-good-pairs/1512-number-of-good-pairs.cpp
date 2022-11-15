class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int c = 0;
        unordered_map<int, vector<int>> ump;
        for (int i = 0; i < nums.size(); i++) {
            if (ump.find(nums[i]) != ump.end()) ump[nums[i]].push_back(i);
            else ump.insert({nums[i], {i}});
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (ump.find(nums[i]) != ump.end()) {
                for (auto& j: ump[nums[i]]) {
                    if (i < j) c++;
                }
            }
        }
        return c;
        
    }
};