class Solution {
public:
    int find(int& node, vector<int>& parent) {
        int prnt;
        if (parent[node] == -1) prnt = node;
        else prnt = find(parent[node], parent);
        return prnt;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int AR1, AR2;
        unordered_set<int> nodes;
        vector<int> parent(edges.size()+1, -1);
        vector<int> redundantEdge;
        for (auto& i : edges) {
            AR1 = find(i[0], parent); AR2 = find(i[1], parent);
            if (AR1 != AR2 || (AR1 == AR2 && AR1 == -1)) parent[AR1] = AR2;
            else redundantEdge = i;
        }

        return redundantEdge;
    }
};