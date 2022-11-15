class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> tmp(101, 0);
        vector<int> res(nums.size(), 0);
        unordered_map<int, vector<int>> ump;
        
        for (int i = 0; i < nums.size(); i++) {
            tmp[nums[i]]++;
            if (ump.find(nums[i]) != ump.end()) ump[nums[i]].push_back(i);
            else ump.insert({nums[i], {i}});
        }
        int temp = 0;
        
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i] != 0) {
                for (auto& j : ump[i]) {
                    res[j] = temp;
                }
                temp = temp + tmp[i];
            }
        }
        return res;
        
    }
};