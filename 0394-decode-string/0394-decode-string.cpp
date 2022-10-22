class Solution {
public:
    string decode(string& s, int& i) {
        string res = "";
        while(i < s.size() and s[i] != ']') {
            if(!isdigit(s[i])) {
                res += s[i++];
            } else {
                int n = 0;
                if(isdigit(s[i])) {
                    while(i < s.size() and isdigit(s[i])) {
                        n = n * 10 + s[i++] - '0'; 
                        cout << n << endl;
                    }
                }
                i++;
                string temp = decode(s, i);
                i++;
                while(n--) {
                    res += temp;
                }
            }
        }
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
};