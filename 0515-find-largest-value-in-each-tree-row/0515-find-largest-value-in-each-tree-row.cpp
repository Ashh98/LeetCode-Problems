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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> arr;
        int curr_row = 1;
        int next_row = 0;
        int max = INT_MIN;
        
        if (!root) return {};
        
        while (!q.empty()) {
            if (q.front()->val >= max) max = q.front()->val;
            if (q.front()->left) {
                next_row++;
                q.push(q.front()->left);
            }
            if (q.front()->right) {
                next_row++;
                q.push(q.front()->right);
            }
            q.pop();
            curr_row--;
            if (curr_row == 0) {
                curr_row = next_row;
                next_row = 0;
                arr.push_back(max);
                max = INT_MIN;
            }
        }
        
        return arr;
        
        
    }
};