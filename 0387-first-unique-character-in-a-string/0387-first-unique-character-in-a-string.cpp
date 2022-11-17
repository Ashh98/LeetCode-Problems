class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> ump;
        int ind = 0;
        vector<int> cArr;
        for (int i = 0; i < s.size(); i++) {
            if (ump.find(s[i]) == ump.end()) {
                ump.insert({s[i], ind});
                cArr.push_back(i);
                ind++;
            }
        }
        vector<int> arr(ump.size(), 0);
        for (int i = 0; i < s.size(); i++) {
            arr[ump[s[i]]]++;
        }
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 1) return cArr[i];
        }
        return -1;
    }
};