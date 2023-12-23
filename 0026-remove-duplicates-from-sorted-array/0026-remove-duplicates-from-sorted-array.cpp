class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; int ptr = 0;
        while (i < nums.size()) {
            nums[ptr]=nums[i];
            ptr++;
            int j=i;
            while (j+1 < nums.size()) {
                if (nums[j] == nums[j+1]) j++;
                else break;
            }
            i=j+1;
        }
        return ptr;
    }
};