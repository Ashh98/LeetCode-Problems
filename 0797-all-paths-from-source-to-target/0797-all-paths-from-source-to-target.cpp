class Solution {
public:
    void allPathsSourceTarget(vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result, stack<int>& s) {
        int node = s.top();
        for (auto& i : graph[node]) {
            s.push(i);
            path.push_back(i);
            allPathsSourceTarget(graph, path, result, s);
        }
        if (node == graph.size()-1) result.push_back(path);
        path.pop_back();
        s.pop();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result; vector<int> path;
        stack<int> s;
        path.push_back(0);
        s.push(0);
        allPathsSourceTarget(graph, path, result, s);
        return result;
    }
};