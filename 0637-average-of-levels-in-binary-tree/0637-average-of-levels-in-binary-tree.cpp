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
    int mHeight;
    vector<double> levelSum;
    vector<double> levelNodes;
    
    int maxHeight(TreeNode* root) {
        if (root == NULL) return -1;
        else return max(maxHeight(root->left), maxHeight(root->right)) + 1;
    }
    
    void setmHeight(TreeNode* root) {
        mHeight = maxHeight(root);
        levelNodes.resize(mHeight + 1, 0.0);
        levelSum.resize(mHeight + 1, 0.0);
    }
    
    void averageOfLevelsOP(TreeNode* root, int Height) {
        if (root != NULL) {
            levelNodes[mHeight - Height] = levelNodes[mHeight - Height] + 1;
            levelSum[mHeight - Height] = levelSum[mHeight - Height] + root->val;
            averageOfLevelsOP(root->left, Height-1);
            averageOfLevelsOP(root->right, Height-1);
        }
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        setmHeight(root);
        averageOfLevelsOP(root, maxHeight(root));
        for (int i = 0; i < levelSum.size(); i++) res.push_back(levelSum[i]/levelNodes[i]);
        return res;
    }
};