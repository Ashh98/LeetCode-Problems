class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> nodes;
        vector<int> result;
        for (auto& i : edges) {
            if (nodes.find(i[0]) == nodes.end()) nodes.insert(i[0]);
            if (nodes.find(i[1]) == nodes.end()) nodes.insert(i[1]);
        }

        vector<int> in_degree(nodes.size(), 0);

        for (auto& i : edges) {
            in_degree[i[1]]++;
        }

        for (int i = 0; i < in_degree.size(); i++) {
            if (in_degree[i] == 0) result.push_back(i);
        }

        return result;
    }
};