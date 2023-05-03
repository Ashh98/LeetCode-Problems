class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums1_s;
        unordered_set<int> nums2_s;
        vector<vector<int>> answer(2);
        for (auto& i : nums1) {
            if (nums1_s.find(i) == nums1_s.end()) nums1_s.insert(i);
        }
        for (auto& i : nums2) {
            if (nums2_s.find(i) == nums2_s.end()) nums2_s.insert(i);
        }
        
        for (auto& i : nums1_s) {
            if (nums2_s.find(i) == nums2_s.end()) answer[0].push_back(i);
        }
        for (auto& i : nums2_s) {
            if (nums1_s.find(i) == nums1_s.end()) answer[1].push_back(i);
        }
        
        return answer;
    }
};