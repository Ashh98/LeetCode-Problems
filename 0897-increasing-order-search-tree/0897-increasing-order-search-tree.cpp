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
    TreeNode* newroot = new TreeNode;
    TreeNode* ptr = newroot;
    
    int& maxValue(TreeNode* root) {  
        TreeNode* current = root;
        while (current->right != NULL) {
            current = current->right;
        }
        return current->val;
    }
    void InorderTrav(TreeNode* root, int& maxTree) {
        if (root != NULL) {
            InorderTrav(root->left, maxTree);
            ptr->val = root->val;
            if (root->val != maxTree) {
                ptr->right = new TreeNode; ptr = ptr->right;
            }
            InorderTrav(root->right, maxTree);
        }
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        InorderTrav(root, maxValue(root));
        return newroot;
    }
};