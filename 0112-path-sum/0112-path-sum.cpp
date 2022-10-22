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
    bool dec = false;
    void hasPathSumOP(TreeNode* root, int targetSum, int sum) {
        if (root) {
            hasPathSumOP(root->left, targetSum, sum + root->val);
            if (!root->left && !root->right) {
                sum = sum + root->val;
                if (sum == targetSum) dec = true;
            }
            hasPathSumOP(root->right, targetSum, sum + root->val);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        hasPathSumOP(root, targetSum, 0);
        return dec;
    }
};