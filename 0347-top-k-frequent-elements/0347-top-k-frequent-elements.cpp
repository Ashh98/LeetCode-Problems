class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        vector<vector<int>> res(nums.size()+1);
        vector<int> vec_res;
        
        for (int i = 0; i < nums.size(); i++) {
            if (ump.find(nums[i]) != ump.end()) {
                ump[nums[i]]++;
            } else {
                ump[nums[i]] = 1;
            }
        }
        
        
        for (auto & i : ump) {
            res[i.second].push_back(i.first);
        }
        
        for (int i = res.size()-1; i >= 0; i--) {
            for (int j = 0; j < res[i].size(); j++) {
                vec_res.push_back(res[i][j]);
                k--;
                if (k==0) return vec_res;
            }
        }
        
        return {};
    }
};