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
    unordered_map<int, int> ump;
    vector<int> res;
    void findModeOP(TreeNode* root) {
        if (root) {
            findModeOP(root->left);
            if (ump.find(root->val) != ump.end()) ump[root->val]++;
            else ump.insert({root->val, 1});
            findModeOP(root->right);
        }
    }
    vector<int> findMode(TreeNode* root) {
        findModeOP(root);
        int tmp = 0;
        for (auto& i : ump) if (i.second > tmp) tmp = i.second;
        for (auto& i : ump) if (i.second == tmp) res.push_back(i.first);
        return res;
    }
};