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
    
    void isUnivalTreeOP(TreeNode* root, int uniVal) {
        if (root != NULL) {
            if (root->val != uniVal) res = false;
            isUnivalTreeOP(root->left, root->val);
            isUnivalTreeOP(root->right, root->val);
        }
    }
    
    bool isUnivalTree(TreeNode* root) {
        isUnivalTreeOP(root, root->val);
        return res;
    }
};