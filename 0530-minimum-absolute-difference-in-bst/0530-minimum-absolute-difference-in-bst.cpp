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
    vector<int> nums;
    
    void Trav(TreeNode* root) {
        if (root) {
            Trav(root->left);
            nums.push_back(root->val);
            Trav(root->right);
        }
    }
    
    void inorderSuccessor(TreeNode* root, int target, bool& ctrl, bool& found, int& res) {
        if (target < root->val && root->left) {
            inorderSuccessor(root->left, target, ctrl, found, res);
            if (ctrl && !found && root->val > target) {
                found = true;
                ctrl = false;
                res = root->val;
            }
        } else if (target > root->val && root->right) {
            inorderSuccessor(root->right, target, ctrl, found, res);
            if (ctrl && !found && root->val > target) {
                found = true;
                ctrl = false;
                res = root->val;
            }
        } else if (target == root->val) {
            if (root->right) res = root->right->val;
            else if (!root->right) {
                found = false;
                ctrl = true;
            }
        }
    }
    
    void inorderPredecessor(TreeNode* root, int target, bool& ctrl, bool& found, int& res) {
        if (target < root->val && root->left) {
            inorderPredecessor(root->left, target, ctrl, found, res);
            if (ctrl && !found && root->val < target) {
                found = true;
                ctrl = false;
                res = root->val;
            }
        } else if (target > root->val && root->right) {
            inorderPredecessor(root->right, target, ctrl, found, res);
            if (ctrl && !found && root->val < target) {
                found = true;
                ctrl = false;
                res = root->val;
            }
        } else if (target == root->val) {
            if (root->left) res = root->left->val;
            else if (!root->left) {
                found = false;
                ctrl = true;
            }
        }
    }
    
    int getMinimumDifference(TreeNode* root) {
        Trav(root);
        bool ctrl1; bool found1; int res1;
        bool ctrl2; bool found2; int res2;
        int minDiff = 10e5+1;
        for (int i = 0; i < nums.size(); i++) {
            res1 = 0; res2 = 0; ctrl1 = false; ctrl2 = false; found1 = false; found2 = false;
            inorderSuccessor(root, nums[i], ctrl1, found1, res1);
            inorderPredecessor(root, nums[i], ctrl2, found2, res2);
            if (i == 0) {
                if (minDiff > res1-nums[i]) minDiff = abs(nums[i]-res1);
            } else if (i == nums.size()-1) {
                if (minDiff > nums[i]-res2) minDiff = nums[i]-res2;
            } else {
                if (minDiff > min(res1-nums[i], nums[i]-res2)) minDiff = min(res1-nums[i], nums[i]-res2);
            }
        }
        return minDiff;
    }
};