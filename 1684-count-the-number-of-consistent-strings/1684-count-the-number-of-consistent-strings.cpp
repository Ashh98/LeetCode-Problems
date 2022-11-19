class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, char> ump;
        int c = 0;
        
        for (auto& i : allowed) {
            ump.insert({i, i});
        }
        
        for (auto& i : words) {
            c++;
            for (auto& j : i) {
                if (ump.find(j) == ump.end()) {
                    c--;
                    break;
                }
            }
        }
        return c;
    }
};