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
class FindElements {
public:
    int c = 0;
    TreeNode* mainRoot;
    
    FindElements(TreeNode* root) {
        mainRoot = Trav(root, 0);
    }
    
    TreeNode* Trav(TreeNode* root, int prev) {
        if (root) {
            if (c == 0) {
                root->val = 0;
                c++;
            } else root->val = prev;
            if (root->left) Trav(root->left, (2*root->val) + 1);
            if (root->right) Trav(root->right, (2*root->val) + 2);
        }
        return root;
    }
    
    bool findOP(TreeNode* root, int target, bool& res) {
        if (root) {
            findOP(root->left, target, res);
            if (root->val == target) res = true;
            findOP(root->right, target, res);
        }
        return res;
    }
    bool find(int target) {
        bool res = false;
        return findOP(mainRoot, target, res);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */