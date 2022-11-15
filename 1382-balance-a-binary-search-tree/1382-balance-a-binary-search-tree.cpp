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
    vector<int> sortedArr;
    
    void inOrderTrav(TreeNode* root) {
        if (root) {
            inOrderTrav(root->left);
            sortedArr.push_back(root->val);
            inOrderTrav(root->right);
        }
    }
    
    TreeNode* balanceBST(int l, int h) {
        int mid = (l+h)/2;
        TreeNode* newNode;
        if (l <= h) {
            newNode = new TreeNode(sortedArr[mid]);
            newNode->left = balanceBST(l, mid-1);
            newNode->right = balanceBST(mid+1, h);
        } else return nullptr;
        return newNode;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        inOrderTrav(root);
        return balanceBST(0, sortedArr.size()-1);
    }
};