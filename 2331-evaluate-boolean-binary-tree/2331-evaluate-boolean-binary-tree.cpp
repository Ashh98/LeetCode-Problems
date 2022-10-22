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
    bool evaluateTree(TreeNode* root) {
        bool y;
        if (root) {
            if (!root->left && !root->right) y = (bool) root->val;
            else {
                if (root->val == 2) y = evaluateTree(root->left) || evaluateTree(root->right);
                else y = evaluateTree(root->left) && evaluateTree(root->right);
            }
        }
        return y;
    }
};