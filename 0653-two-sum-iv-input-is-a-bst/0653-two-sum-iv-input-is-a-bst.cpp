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
    unordered_map<int,int> ump;
    
    void Trav(TreeNode* root) {
        if (root) {
            Trav(root->left);
            ump.insert( {root->val, 1} );
            Trav(root->right);
        }
    }
    
    bool findTarget(TreeNode* root, int k) {
        Trav(root);
        int tmp;
        bool decT = false;
        for (auto& i: ump) {
            if (k >= tmp) {
                if (ump.find(k-i.first) != ump.end()) {
                    i.second--;
                    if (ump[k-i.first] == 1) {
                        decT = true;
                        break;
                    }
                    else i.second++;
                }
            }
        }
        return decT;
    }
};