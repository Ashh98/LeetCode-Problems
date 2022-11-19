class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> ump;
        for (auto& i : nums) {
            if (ump.find(i) != ump.end()) ump[i]++;
            else ump.insert({i, 1});
        }
        for (auto& i : ump) {
            if (i.second%2 == 1) return false;
        }
        return true;
    }
};