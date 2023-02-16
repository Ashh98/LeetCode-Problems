class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, vector<int>> ump;
        vector<int> result;
        int tmp = 0;
        
        for (auto& i : nums1) {
            if (ump.find(i) == ump.end()) ump[i] = {1, 0, 0};
            else ump[i][0]++;
        }
        
        for (auto& i : nums2) {
            if (ump.find(i) == ump.end()) ump[i] = {0, 1, 0};
            else ump[i][1]++;
        }
        
        for (auto& i : nums3) {
            if (ump.find(i) == ump.end()) ump[i] = {0, 0, 1};
            else ump[i][2]++;
        }
        
        for (auto& i : ump) {
            tmp = 0;
            for (auto& j : i.second) {
                if (j) tmp += 1;
            } 
            if (tmp > 1) result.push_back(i.first);
        }
        
        return result;
    }
};