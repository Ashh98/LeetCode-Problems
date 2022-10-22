/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* root = new TreeNode;
    
    void sortedArrayToBSTOP(vector<int>& nums, TreeNode* root, int lo, int hi) {
        int mid;
        if (lo == hi) {
            root->val = nums[lo];
        } else if (hi - lo == 1) {
            root->val = nums[lo];
            root->right = new TreeNode;
            root->right->val = nums[hi];
        } else if (hi - lo > 1) {
            mid = (lo+hi)/2;
            root->val = nums[mid];
            root->left = new TreeNode;
            root->right = new TreeNode;
            sortedArrayToBSTOP(nums, root->left, lo, mid-1);
            sortedArrayToBSTOP(nums, root->right, mid+1, hi);
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        sortedArrayToBSTOP(nums, root, 0, nums.size()-1);
        return root;
    }
};