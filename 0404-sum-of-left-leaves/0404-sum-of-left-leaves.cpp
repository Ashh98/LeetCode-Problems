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
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if (root) {
            sumOfLeftLeaves(root->left);
            if (!(root->left) && !(root->right)) sum = sum + 0;
            else if ((!root->left) && (root->right)) sum = sum + 0;
            else if (!(root->left)->left && !(root->left)->right) sum = sum + root->left->val;
            sumOfLeftLeaves(root->right);
        }
        return sum;
    }
};