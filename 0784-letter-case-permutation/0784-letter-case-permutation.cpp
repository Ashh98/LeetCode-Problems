class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int c = 0; int tmp = 0; string t;
        vector<string> res;
        for (auto& i : s) {
            if (isalpha(i)) c++;
        }
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for (int i = 0; i < pow(2, c); i++) {
            t = s;
            int ind = 0;
            tmp = i;
            while (tmp) {
                if (isalpha(t[ind])) {
                    if (tmp%2) t[ind] = toupper(t[ind]);
                    tmp >>= 1;
                }
                ind++;
            }
            res.push_back(t);
        } 
        return res;
    }
};