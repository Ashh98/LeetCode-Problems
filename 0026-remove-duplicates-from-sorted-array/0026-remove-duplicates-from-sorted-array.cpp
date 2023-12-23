class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> uniq;
        int i = 0;
        while (i < nums.size()) {
            int j=i;
            uniq.push_back(i);
            while (j+1 < nums.size()) {
                if (nums[j] == nums[j+1]) j++;
                else break;
            }
            i=j+1;
        }
        for (int i = 0; i < uniq.size(); i++) {
            nums[i] = nums[uniq[i]];
        }
        return uniq.size();
    }
};