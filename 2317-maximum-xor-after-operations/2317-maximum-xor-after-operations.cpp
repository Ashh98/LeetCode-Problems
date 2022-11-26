class Solution {
public:
    int getXOR(vector<int>& arr) {
        int xor_res = 0;
        for (auto& i : arr) {
            xor_res ^= i;
        }
        return xor_res;
    }
    
    int maximumXOR(vector<int>& nums) {
        int max = 0, mult = 1, num = 0, max_ind = 0, element = 0;
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
                element = (nums[i] & ((mult*2)-1));
                if ((element ^ mult) == (element - mult)) {
                    num++;
                    if (element > max) {
                        max = element;
                        max_ind = i;
                    }
                }
            }
            if (num%2 == 0) nums[max_ind] = nums[max_ind] & (nums[max_ind] ^ mult);
            mult /= 2;
        }
        
        return getXOR(nums);
    }
};