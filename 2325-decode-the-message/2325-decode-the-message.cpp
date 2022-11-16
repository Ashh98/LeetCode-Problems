class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        unordered_map<char, char> ump;
        string res;
        
        int k = 0;
        for (int i = 0; i < key.size(); i++) {
            if (k == 26) break;
            if (key[i] != ' ') {
                if (ump.find(key[i]) == ump.end()) {
                    ump.insert({key[i], alphabet[k]});
                    k++;
                }
            }
        }
        
        for (int i = 0; i < message.size(); i++) {
            if (message[i] != ' ') {
                res.push_back(ump[message[i]]);
            } else {
                res.push_back(' ');
            }
        }
        return res;
    }
};