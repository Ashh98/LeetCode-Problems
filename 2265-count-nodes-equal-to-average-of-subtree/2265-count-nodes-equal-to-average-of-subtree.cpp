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
    struct res {
        int count = 0;
        int sum = 0;
    };
    int num = 0;
    res averageOfSubtreeOP(TreeNode* root) {
        if (root) {
            if (!root->left && !root->right) {
                res resNode;
                resNode.count = 1;
                resNode.sum = root->val;
                if (resNode.sum/resNode.count == root->val) num++;
                return resNode;
            } else {
                res resNodeL = averageOfSubtreeOP(root->left);
                res resNodeR = averageOfSubtreeOP(root->right);
                res resNode;
                resNode.count = resNodeL.count + resNodeR.count + 1;
                resNode.sum = root->val + resNodeL.sum + resNodeR.sum;
                if (resNode.sum/resNode.count == root->val) num++;
                return resNode;
                
            }
        } else return {0, 0};
    }
    int averageOfSubtree(TreeNode* root) {
        averageOfSubtreeOP(root);
        return num;
    }
};