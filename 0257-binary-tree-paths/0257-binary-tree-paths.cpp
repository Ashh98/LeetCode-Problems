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
    vector<string> res;
    
    void binaryTreePaths(TreeNode* root, string s) {
        if (root != NULL) {
            if (!root->left && !root->right) {
                s+=to_string(root->val);
                res.push_back(s);
            } else s+=to_string(root->val) + "->";
            binaryTreePaths(root->left, s);
            binaryTreePaths(root->right, s);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        binaryTreePaths(root, "");
        return res;
    }
};