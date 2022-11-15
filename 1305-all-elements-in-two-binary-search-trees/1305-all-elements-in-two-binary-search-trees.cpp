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
    vector<int> res;
    
    void inOrderTrav(TreeNode* root, vector<int>& arr) {
        if (root) {
            inOrderTrav(root->left, arr);
            arr.push_back(root->val);
            inOrderTrav(root->right, arr);
        }
    }
    
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1;
        vector<int> arr2;
        inOrderTrav(root1, arr1);
        inOrderTrav(root2, arr2);
        
        int i = 0, j = 0;
        while (i < arr1.size() || j < arr2.size()) {
            if (i == arr1.size()) {
                for (int x = j; x < arr2.size(); x++) {
                    res.push_back(arr2[x]);
                }
                j = arr2.size();
                break;
            } else if (j == arr2.size()) {
                for (int x = i; x < arr1.size(); x++) {
                    res.push_back(arr1[x]);
                }
                i = arr1.size();
                break;
            }
            if (arr1[i] >= arr2[j]) {
                res.push_back(arr2[j]);
                j++;
            } else if (arr1[i] <= arr2[j]) {
                res.push_back(arr1[i]);
                i++;
            }
        }
        return res;
    }
};