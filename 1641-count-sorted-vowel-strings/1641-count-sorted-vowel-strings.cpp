class Solution {
public:
    
    void helper(vector<char>& vowels,int ind, int n, int& cnt) {
        if (n>=1) {
            for(int i = ind; i < vowels.size(); i++) {
                helper(vowels, i, n-1, cnt);
                if(n==1) cnt++;
            }
        }
    }
    
    int countVowelStrings(int n) {
        int cnt=0;
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        helper(vowels, 0, n, cnt);
        return cnt;
    }
};