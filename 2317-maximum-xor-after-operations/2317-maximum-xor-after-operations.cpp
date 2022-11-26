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
        int num = 0, ind = 0, element = 0, max_ele = *max_element(nums.begin(), nums.end());
        int mult;
        if (max_ele == 0) mult = 1;
        else mult = pow(2, (int) log2(*max_element(nums.begin(), nums.end())));

        while (mult) {
            num = 0; ind = 0;
            for (int i = 0; i < nums.size(); i++) {
                element = (nums[i] & ((mult*2)-1));
                if ((element ^ mult) == (element - mult)) {
                    num++;
                    ind = i;
                }
            }
            if (num%2 == 0) nums[ind] = nums[ind] & (nums[ind] ^ mult);
            mult /= 2;
        }
        
        return getXOR(nums);
    }
};