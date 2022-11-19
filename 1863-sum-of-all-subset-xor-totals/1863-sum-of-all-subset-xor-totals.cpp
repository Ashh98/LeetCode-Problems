class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int pw = 1; int tmp = pw;
        int ind = 0;
        int xorSubset = 0; int res = 0;

        for (int i = 0; i < pow(2,nums.size())-1; i++) {
            while(tmp) {
                if (tmp%2 == 1) xorSubset = xorSubset ^ nums[ind];
                ind++;
                tmp >>= 1;
            }
            res += xorSubset; xorSubset = 0;
            pw++; tmp = pw; ind = 0;
        }
        
        return res;
    }
};