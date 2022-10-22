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
    void invertOP(TreeNode* root) {
        TreeNode* tmp;
        if (root != NULL) {
            tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            invertTree(root->left);
            invertTree(root->right);
        }   
    }
    TreeNode* invertTree(TreeNode* root) {
        invertOP(root);
        return root;
    }
};