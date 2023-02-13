class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> ump;
        
        for (auto& i : nums) {
            if (ump.find(i) != ump.end()) ump[i]++;
            else ump[i] = 1;
        }
        
        for (auto& i : ump) {
            if (i.second == nums.size()/2) return i.first;
        }
        
        return 0;
    }
};