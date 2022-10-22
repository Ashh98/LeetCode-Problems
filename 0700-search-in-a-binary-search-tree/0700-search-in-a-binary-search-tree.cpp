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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* res;
        if (root->val > val && root->left != NULL) res = searchBST(root->left, val);
        else if (root->val < val && root->right != NULL) res = searchBST(root->right, val);
        else if (root->val == val) res = root;
        else if (root->right == NULL && root->left == NULL && root->val != val) res = NULL;
        return res;
    }
};