class Solution {
public:
    
    int xorArr(vector<int>& nums) {
        int xorVal = 0;
        for (int i = 0; i < nums.size(); i++) {
            xorVal = xorVal ^ nums[i];
        }
        return xorVal;
    }
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int k = 0, xorVal, tmp;
        vector<int> result;
        xorVal = xorArr(nums);
        while (nums.size()) {
            for (int i = 0; i < maximumBit; i++) {
                tmp = xorVal;
                tmp >>= i;
                if (!(tmp%2)) k = k + pow(2, i);
            }
            xorVal ^= nums[nums.size()-1];
            result.push_back(k);
            nums.pop_back();
            k = 0;
        }
        return result;
    }
};