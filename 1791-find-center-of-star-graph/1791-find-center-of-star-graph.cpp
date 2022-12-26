class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> nodes(edges.size()+2, 0);
        
        for (auto& i : edges) {
            nodes[i[0]]++;
            nodes[i[1]]++;
        }
        
        for (int i = 0; i < nodes.size(); i++) if (nodes[i] == edges.size()) return i;
        
        return -1;
    }
};