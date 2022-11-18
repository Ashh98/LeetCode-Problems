class Solution {
public:
    int minBitFlips(int start, int goal) {
        int c = 0;
        while (start || goal) {
            if (start%2 != goal%2) c++;
            start >>= 1;
            goal >>= 1;
        }
        return c;
        
    }
};