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
    int nLeaf = 0;
    int sum = 0;
    
    void noOfLeafNodes(TreeNode* root, int depth) {
        if (root != NULL) {
            if (root->left != NULL) noOfLeafNodes(root->left, depth+1);
            if (root->left == NULL && root->right == NULL) nLeaf = nLeaf + pow(2,depth);
            if (root->right != NULL) noOfLeafNodes(root->right, depth+1);
        }
    }
    
    void bufferLeaf(TreeNode* root) {
        nLeaf = 0;
        noOfLeafNodes(root, 0);
    }
    
    void sumRootToLeafOP(TreeNode* root) {
        if (root != NULL) {
            bufferLeaf(root);
            sum = sum + (nLeaf * root->val);
            sumRootToLeaf(root->left);
            sumRootToLeaf(root->right);
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        sumRootToLeafOP(root);
        return sum;
    }
};