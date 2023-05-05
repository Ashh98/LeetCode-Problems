class Solution {
public:
    bool isVowel(char& l) {
        if (l == 'a' || l == 'o' || l == 'e' || l == 'i' || l == 'u') return true;
        return false;
    }
    
    int maxVowels(string s, int k) {
        int c = 0;
        int c_largest = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                for (int j = 0; j < k; j++) {
                    if (isVowel(s[j])) c++;
                }
                i += k-1;
            } else {
                if (isVowel(s[i-k])) c--;
                if (isVowel(s[i])) c++;
            }
            
            if (c > c_largest) c_largest = c;
        }
        return c_largest;
    }
};