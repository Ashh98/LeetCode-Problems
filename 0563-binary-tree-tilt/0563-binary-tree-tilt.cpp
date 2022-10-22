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
    int res = 0;
    
    int Trav(TreeNode* root, int& s) {
        if (root!= NULL) {
            s += root->val;
            Trav(root->left, s);
            Trav(root->right, s);
        }
        return s;
    }
    
    int findTilt(TreeNode* root) {
        int s = 0;
        int t = 0;
        if (root && root->left && root->right) {
            res = res + abs( Trav(root->right, s) -  Trav(root->left, t) );
            findTilt(root->left);
            findTilt(root->right);
        } else if (root && !root->left && root->right) {
            res = res + abs(0-Trav(root->right, s));
            findTilt(root->right);
        } else if (root && root->left && !root->right) {
            res = res + abs(Trav(root->left, s));
            findTilt(root->left);
        } else if (root && !root->left && !root->right) res = res + 0;
        return res;
    }
};