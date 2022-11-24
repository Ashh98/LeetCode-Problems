class Solution {
public:
    void selectionSort(vector<int>& arr) {
        int iMin;
        for (int i = 0; i < arr.size()-1; i++) {
            iMin = i;
            for (int j = i+1; j < arr.size(); j++) {
                if (arr[j] < arr[iMin]) iMin = j;
            }
            swap(arr[i], arr[iMin]);
        }
    }
    int maxProductDifference(vector<int>& nums) {
        int numsSize = nums.size()-1;
        selectionSort(nums);
        return ((nums[numsSize]*nums[numsSize-1]) - (nums[0]*nums[1]));
    }
};