class Solution {
public:
    void pushString(string& t, string& p) {
        for (auto& i : p) {
            t.push_back(i);
        }
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<char, string> ump = {
            {'a', ".-"},
            {'b', "-..."},
            {'c', "-.-."},
            {'d', "-.."},
            {'e', "."},
            {'f', "..-."},
            {'g', "--."},
            {'h', "...."},
            {'i', ".."},
            {'j', ".---"},
            {'k', "-.-"},
            {'l', ".-.."},
            {'m', "--"},
            {'n', "-."},
            {'o', "---"},
            {'p', ".--."},
            {'q', "--.-"},
            {'r', ".-."},
            {'s', "..."},
            {'t', "-"},
            {'u', "..-"},
            {'v', "...-"},
            {'w', ".--"},
            {'x', "-..-"},
            {'y', "-.--"},
            {'z', "--.."}
        };
        unordered_set<string> uset; string t;        
        for (int i = 0; i < words.size(); i++) {
            t.clear();
            for (auto& j : words[i]) {
                pushString(t, ump[j]);
            }
            if (uset.find(t) == uset.end()) uset.insert({t});
        }
        return uset.size();
    }
};