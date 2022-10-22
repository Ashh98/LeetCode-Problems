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
    string tree2str(TreeNode* root) {
        string res;
        if (root && root->left && root->right) {
            res = to_string(root->val);
            res += "(" + tree2str(root->left) + ")";
            res += "(" + tree2str(root->right) + ")";
        } else if (root && root->left && !root->right) {
            res = to_string(root->val);
            res += "(" + tree2str(root->left) + ")";
        } else if (root && !root->left && root->right) {
            res = to_string(root->val);
            res += "()";
            res += "(" + tree2str(root->right) + ")";
        } else if (root && !root->left && !root->right) res = to_string(root->val);
        return res;
    }
};