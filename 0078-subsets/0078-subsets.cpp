class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int numSize = nums.size();
        int tmp;
        vector<vector<int>> result;
        vector<int> element {};
        for (int i = 0; i < pow(2, numSize); i++) {
            for (int j = 0; j < numSize; j++) {
                tmp = i;
                tmp >>= j;
                if (tmp%2) element.push_back(nums[j]);
            }
            result.push_back(element);
            element.clear();
        }
        return result;
    }
};