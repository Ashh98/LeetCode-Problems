class Solution {
public:
    char findTheDifference(string s, string t) {
        int s_int = int(s[0]), t_int = int(t[0]);
        for (int i = 1; i < s.size(); i++) {
            s_int = s_int ^ s[i];
        }
        for (int i = 1; i < t.size(); i++) {
            t_int = t_int ^ t[i];
        }
        return char(s_int ^ t_int);
    }
};