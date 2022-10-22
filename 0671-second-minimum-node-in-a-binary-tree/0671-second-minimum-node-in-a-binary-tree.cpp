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
    long long min1 = 2147483648;
    long long min2 = 2147483648;
    void findSecondMinimumValueMIN1(TreeNode* root) {
        if (root) {
            findSecondMinimumValueMIN1(root->left);
            if (min1 > root->val) min1 = root->val;
            findSecondMinimumValueMIN1(root->right);
        }
    }
    void findSecondMinimumValueMIN2(TreeNode* root) {
        if (root) {
            findSecondMinimumValueMIN2(root->left);
            if (min2 > root->val && root->val > min1) min2 = root->val;
            findSecondMinimumValueMIN2(root->right);
        }
    }
    long long findSecondMinimumValue(TreeNode* root) {
        findSecondMinimumValueMIN1(root);
        findSecondMinimumValueMIN2(root);
        if (min2 == 2147483648) return -1;
        else return min2;
    }
};