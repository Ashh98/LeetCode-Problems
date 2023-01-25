class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> ump;
        for (auto& i : s) {
            if (ump.find(i) != ump.end()) ump[i]++;
            else ump[i] = 1;
        }
        int prev = 0;
        for (auto it = ump.begin(); it != ump.end(); it++) {
            if (it == ump.begin()) prev = it->second;
            else {
                if (it->second != prev) return false;
                else prev = it->second;
            }
        }
        
        return true;
    }
};