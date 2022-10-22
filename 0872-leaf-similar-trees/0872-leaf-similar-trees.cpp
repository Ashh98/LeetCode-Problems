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
    vector<int> res1;
    vector<int> res2;
    
    void findLeafNodes(TreeNode* root, vector<int>& res) {
        if (root != NULL) {
            findLeafNodes(root->left, res);
            if (root->left == NULL && root->right == NULL) res.push_back(root->val);
            findLeafNodes(root->right, res);
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        bool result = true;
        findLeafNodes(root1, res1);
        findLeafNodes(root2, res2);
        for (int i = 0; i < max(res1.size(), res2.size()); i++) {
            cout << res1[i] << " " << res2[i] << endl;
            if (res1[i] != res2[i]) {
                result = false;
                break;
            }
        }
        return result;
    }
};