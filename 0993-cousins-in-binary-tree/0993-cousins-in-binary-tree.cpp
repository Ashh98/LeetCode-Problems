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
    bool dec;
    pair<int, int> p1;
    pair<int, int> p2;
    int parent1;
    int parent2;

    
    void isCousinsOP(TreeNode* root, int x, int y, int depth) {
        if (root) {
            isCousinsOP(root->left, x, y, depth+1);
            if (root->val == x) {
                p1.first = root->val;
                p1.second = depth;
            } else if (root->val == y) {
                p2.first = root->val;
                p2.second = depth;
            }
            if (root->right && root->left) {
                if (root->right->val == x || root->left->val == x) parent1 = root->val;
                if (root->right->val == y || root->left->val == y) parent2 = root->val;
            } else if (root->right && !root->left) {
                if (root->right->val == x) parent1 = root->val;
                if (root->right->val == y) parent2 = root->val;
            } else if (!root->right && root->left) {
                if (root->left->val == x) parent1 = root->val;
                if (root->left->val == y) parent2 = root->val;
            }
            isCousinsOP(root->right, x, y, depth+1);
        }      
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        isCousinsOP(root, x, y, 0);
        if (p1.second == p2.second && parent1 != parent2) dec = true;
        else dec = false;
        return dec;
    }
};