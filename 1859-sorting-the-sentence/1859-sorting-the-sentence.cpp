class Solution {
public: 
    int getLength(string& s) {
        int c = 1;
        for (auto& i : s) {
            if (i == ' ') c++;
        }
        return c;
    }
        
    string sortSentence(string s) {
        vector<string> str(getLength(s));
        string res;
        string tmp; string ind;
        unordered_set<char> uset = {
            {'0'},
            {'1'},
            {'2'},
            {'3'},
            {'4'},
            {'5'},
            {'6'},
            {'7'},
            {'8'},
            {'9'}
        };
        
        for (int i = 0; i < s.size(); i++) {
            if (uset.find(s[i]) != uset.end()) {
                while(uset.find(s[i]) != uset.end()) {
                    ind.push_back(s[i]);
                    i++;
                }
                str[stoi(ind)-1] = tmp;
                ind.clear(); tmp.clear();
            } else {
                if (s[i] != ' ') tmp.push_back(s[i]);
            }
        }
        
        for (auto& i : str) {
            for (int j = 0; j < i.size(); j++) {
                if (j == i.size()-1) {
                    res.push_back(i[j]); res.push_back(' ');
                } else {
                    res.push_back(i[j]);
                }
            }
        }
        res.pop_back();
        
        return res;
    }
};