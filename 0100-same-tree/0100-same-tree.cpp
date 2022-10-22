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
    bool dec = true;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p != NULL && q != NULL) {
            isSameTree(p->left, q->left);
            if (p->val != q->val) dec = false;
            isSameTree(p->right, q->right);
        } else if ( (!p && q) || (p && !q) ) {
            dec = false;
        }
        return dec;
        
    }
};