class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> ump;
        vector<int> result(2, 0);
        
        for (auto& i : nums) {
            if (ump.find(i) != ump.end()) ump[i]++;
            else ump[i] = 1;
        }
        
        for (auto& i : ump) {
            result[0] += i.second/2;
            i.second = i.second % 2;
            if (i.second == 1) result[1]++;
        }
        
        return result;
    }
};