class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        if (label == 1) return {1};
        
        int low = 2; int high = 2 * 2; int h = 2;
        int ldiff = 0; int hdiff = 0;
        
        while (!(label >= low && label <= high-1)) {
            low *= 2; high *= 2; h++;
        }
        vector<int> path(h, 0);
        path[0] = 1; path[h-1] = label;
        
        label = label/2;
        low = low/2; high = high/2;
        h = h-1;
        while (label > 1) {          
            ldiff = abs(low - label); hdiff = abs(high - 1 - label);
            if (ldiff < hdiff) path[h-1] = high-ldiff-1;
            else path[h-1] = hdiff + low;
            label = path[h-1]/2; low = low/2; high = high/2; h = h-1;
        }
        return path;
    }
};