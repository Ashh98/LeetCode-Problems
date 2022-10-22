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
    int sumTree(TreeNode* root, int& sum) {
        if (root) {
            sumTree(root->left, sum);
            sum = sum + root->val;
            sumTree(root->right, sum);
        }
        return sum;
    }
    
    void bstToGst(TreeNode* root, int& sum) {
        int deduct;
        if (root) {
            bstToGst(root->left, sum);
            deduct = root->val;
            root->val = sum;
            sum = sum - deduct;
            bstToGst(root->right, sum);
        }
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        sum = sumTree(root, sum);
        bstToGst(root, sum);
        return root;
    }
};