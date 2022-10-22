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
    int maxHeight;
    int findHeight(TreeNode* root) {
        if (!root) return -1;
        else return max(findHeight(root->left), findHeight(root->right)) + 1;
    }
    
    int deepestLeavesSumOP(TreeNode* root, int& sum, int depth, int& maxHeight) {
        if (root) {
            deepestLeavesSumOP(root->left, sum, depth+1, maxHeight);
            if (depth == maxHeight) sum = sum + root->val;
            deepestLeavesSumOP(root->right, sum, depth+1, maxHeight);
        }
        return sum;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0; maxHeight = findHeight(root);
        return deepestLeavesSumOP(root, sum, 0, maxHeight);
    }
};