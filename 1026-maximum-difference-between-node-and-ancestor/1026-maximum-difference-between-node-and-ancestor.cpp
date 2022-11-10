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
    int max = 0;
    int maxAncestorDiff(TreeNode* root, vector<int> path) {
        if (root) {
            if (path.size() == 0) {
                path.push_back(root->val);
            } else {
                for (auto& i: path) {
                    if (abs(root->val - i) > max) max = abs(root->val - i);
                }
                path.push_back(root->val);
            }
            maxAncestorDiff(root->left, path);
            maxAncestorDiff(root->right, path);
        }
        return max;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        vector<int> path;
        return maxAncestorDiff(root, path);
    }
};