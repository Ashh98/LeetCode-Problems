class Solution {
public:
    void shellSort(vector<int>& arr) {
        for (int i = arr.size()/2; i > 0; i /= 2) {
            for (int j = i; j < arr.size(); j++) {
                int hole = j;
                while (hole > 0 && arr[hole] < arr[hole-i]) {
                    swap(arr[hole], arr[hole-i]);
                    hole -= i;
                    if (hole - i < 0) break;
                }
            }
        }
    }
    
    int maxProduct(vector<int>& nums) {
        int numsSize = nums.size()-1;
        shellSort(nums);
        return (nums[numsSize]-1) * (nums[numsSize-1]-1);
    }
};