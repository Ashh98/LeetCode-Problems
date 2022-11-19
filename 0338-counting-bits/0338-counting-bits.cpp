class Solution {
public:
    int countOnes(int x) {
        int c = 0;
        while (x) {
            if (x%2 == 1) c++;
            x >>= 1;
        }
        return c;
    }
    
    vector<int> countBits(int n) { 
        vector<int> res;
        
        for (int i = 0; i < n+1; i++) {
            res.push_back(countOnes(i));
        }
        return res;
    }
};