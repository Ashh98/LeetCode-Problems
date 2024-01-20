class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        unordered_set<int> result;
        vector<int> vec_res;
        
        for (int i = 0; i < nums.size(); i++) {
            if (ump.find(nums[i]) != ump.end()) {
                ump[nums[i]]++;
            } else {
                ump[nums[i]] = 1;
            }
        }
        
        
        for (int i = 0; i < k; i++) {
            int maxEle = INT_MIN, num;
            for (auto& i : ump) {
                if (i.second > maxEle && result.find(i.first) == result.end()) {
                    num = i.first; maxEle = i.second;
                }
            }
            result.insert(num);
        }
        vec_res.insert(vec_res.end(), result.begin(), result.end());
        return vec_res;
    }
};