class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int c = 0; int tmp = 0;
        vector<string> res;
        for (auto& i : s) {
            if (isalpha(i)) c++;
        }
        for (int i = 0; i < pow(2, c); i++) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            int ind = 0;
            tmp = i;
            while (tmp) {
                if (isalpha(s[ind])) {
                    if (tmp%2) s[ind] = toupper(s[ind]);
                    tmp >>= 1;
                    ind++;
                } else {
                    ind++;
                }
            }
            res.push_back(s);
        } 
        return res;
    }
};