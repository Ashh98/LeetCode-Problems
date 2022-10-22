/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> nodes;
        nodes.push(cloned);
        TreeNode* tmp;
        while(nodes.front() != NULL) {
            if (nodes.front()->val == target->val) {
                tmp = nodes.front();
                break;
            } else {
                tmp = nodes.front();
                nodes.pop();
                if (tmp->left != NULL) nodes.push(tmp->left);
                if (tmp->right != NULL) nodes.push(tmp->right);
            }
        }
        return tmp;
    }
};