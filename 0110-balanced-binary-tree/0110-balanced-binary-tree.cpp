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
    int findHeight(TreeNode* root) {
        if (!root) return -1;
        else return max(findHeight(root->left), findHeight(root->right)) + 1;
    }
    bool dec = true;
    bool isBalanced(TreeNode* root) {
        if (root) {
            isBalanced(root->left);
            if (abs(findHeight(root->left)-findHeight(root->right)) > 1) dec = false;
            isBalanced(root->right);
        }
        return dec;
    }
};