class Solution {
public:
    vector<int> diStringMatch(string s) {
        int fCount = 0;
        int lCount = s.size();
        int sSize = lCount;
        vector<int> vect(lCount+1, 0);
        for (int i = 0; i < sSize+1; i++) {
            if (i <= sSize-1) {
                if (s[i] == 'I') {
                    vect[i] = fCount;
                    fCount++;
                } else {
                    vect[i] = lCount;
                    lCount--;
                }
            } else if (i == sSize) {
                if (s[i-1] == 'I') vect[i] = vect[i-1]+1;
                else vect[i] = vect[i-1]-1;
            }
        }
        return vect;
    }
};