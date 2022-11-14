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
    bool res = true;
    void isValidBST(TreeNode* root, long lo, long hi) {
        if (root) {
            if (root->val > lo && root->val < hi) {
                isValidBST(root->left, lo, root->val);
                isValidBST(root->right, root->val, hi);
            } else res = false;
        }
    }
    
    bool isValidBST(TreeNode* root) {
        isValidBST(root, LONG_MIN, LONG_MAX);
        return res;
    }
};