class Solution {
public:
    struct res {
        int product = 1;
        int zeros = 0;
    };
    res getProduct(vector<int>& nums) {
        res resNode;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                resNode.zeros++;
                if (resNode.zeros == 2) {
                    resNode.product = 0;
                    break;
                }
            } else {
                resNode.product = resNode.product * nums[i];
            }
        }
        return resNode;
    }
    
    vector<int> productExceptSelf(vector<int>& nums) {
        res resNode = getProduct(nums);
        if (resNode.zeros == 1) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) nums[i] = resNode.product;
                else nums[i] = 0;
            }
        } else if (resNode.zeros == 2) {
            for (int i = 0; i < nums.size(); i++) {
                nums[i] = 0;
            }
        } else {
            for (int i = 0; i < nums.size(); i++) {
                nums[i] = resNode.product/nums[i];
            }
        }
        return nums;
    }
};