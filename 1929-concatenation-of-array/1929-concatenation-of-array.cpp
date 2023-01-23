class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int numSize = nums.size();
        vector<int> result(2*numSize, 0);
        for (int i = 0; i < 2*numSize; i++) result[i] = nums[i%numSize];
        return result;
    }
};