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
    
    void reverse(TreeNode* root) {
        queue<TreeNode*> q1;
        q1.push(root);
        TreeNode* tmp;
        while (!q1.empty()) {
            if (q1.front()->left) q1.push(q1.front()->left);
            if (q1.front()->right) q1.push(q1.front()->right);
            tmp = q1.front()->right;
            q1.front()->right = q1.front()->left;
            q1.front()->left = tmp;
            q1.pop();
        }
    }
    
    void compare(TreeNode* root1, TreeNode* root2) {
        if (root1 && root2) {
            compare(root1->left, root2->left);
            cout << root1->val << " " << root2->val << endl;
            if (root1->val != root2->val) dec = false;
            compare(root1->right, root2->right);
        } else if ((!root1 && root2) || (root1 && !root2)) {
            dec = false;
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root->left) reverse(root->left);
        compare(root->left, root->right);
        return dec;
    }
};