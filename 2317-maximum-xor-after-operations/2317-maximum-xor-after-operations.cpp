class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int max = 0; int mult = 1; int num = 0; int max_ind = 0;
        int xor_res = 0;
        for (auto& i : nums) {
            if (i > max) max = i;
        }
        
        while (true) {
            if (max > mult) mult *= 2;
            else {
                mult /= 2;
                break;
            }
        }
        
        while (mult) {
            num = 0; max_ind = 0; max = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (((nums[i] & ((mult*2)-1)) ^ mult) == (nums[i] & ((mult*2)-1)) - mult) {
                    num++;
                    if ((nums[i] & ((mult*2)-1)) > max) {
                        max = (nums[i] & ((mult*2)-1));
                        max_ind = i;
                    }
                }
            }

            if (num%2 == 0) nums[max_ind] = nums[max_ind] & (nums[max_ind] ^ mult);
            
            mult /= 2;
        }
        
        for (auto& i : nums) {
            xor_res ^= i;
        }
        
        return xor_res;
    }
};