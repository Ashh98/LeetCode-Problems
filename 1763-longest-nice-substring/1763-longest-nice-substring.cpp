class Solution {
public:
    
    
    bool checkNice(string& s) {
        unordered_map<char, char> ump;
        for (auto& i : s) {
            if (ump.find(i) == ump.end()) ump.insert({i, i});
        }
        
        for (auto& i : s) {
            if (isupper(i)) {
                if (ump.find(tolower(i)) == ump.end()) return false;
            } else {
                if (ump.find(toupper(i)) == ump.end()) return false;
            }
        }
        return true;
    }
    
    string longestNiceSubstring(string s) {
        int n = s.size(); string res = "";
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= n-i; j++) {
                string test = s.substr(j, i);
                if (checkNice(test)) {
                    if (test.size() > res.size()) res = test;
                }
            }
        }
        
        return res;
    }
};