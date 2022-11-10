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
    int max_diff = INT_MIN;
    int maxAncestorDiff(TreeNode* root, int mn, int mx) {
        if (root) {
            mn = min(mn, root->val);
            mx = max(mx, root->val);
            maxAncestorDiff(root->left, mn, mx);
            maxAncestorDiff(root->right, mn, mx);
        } else {
            max_diff = max(max_diff, abs(mn-mx));
        }
        return max_diff;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int mn = INT_MAX, mx = INT_MIN;
        return maxAncestorDiff(root, mn, mx);
    }
};