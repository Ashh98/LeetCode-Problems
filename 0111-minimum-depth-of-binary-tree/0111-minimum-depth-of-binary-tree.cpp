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
    int minD = 10e5+1;
    
    void minDepthOP(TreeNode* root, int depth) {
        if (root != NULL) {
            if (root->left != NULL) minDepthOP(root->left, depth+1);
            if (root->left == NULL && root->right == NULL) {
                if (depth < minD) minD = depth;
            }
            if (root->right != NULL) minDepthOP(root->right, depth+1);
        }
    }
    
    int minDepth(TreeNode* root) {
        minDepthOP(root, 1);
        if (minD == 10e5+1) minD = 0;
        return minD;
    }
};