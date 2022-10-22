/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepthOP(Node* root) {
        int c = 0;
        for (int i = 0; i < root->children.size(); i++) c = max(c, maxDepth(root->children[i]));
        return c+1;
    }
    int maxDepth(Node* root) {
        if (!root) return 0;
        else return maxDepthOP(root);
    }
};