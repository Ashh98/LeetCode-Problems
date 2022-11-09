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
    int count = 1;
    
    int goodNodes(TreeNode* root, int prev) {
        int x;
        if (root) {
            if (prev == INT_MIN) x = root->val;
            else {
                if (root->val >= prev) {
                    count++;
                    x = root->val;
                }
                else x = prev;
            }
            goodNodes(root->left, x);
            goodNodes(root->right, x);
        }
        return count;
    }
    int goodNodes(TreeNode* root) {
        return goodNodes(root, INT_MIN);
    }
};