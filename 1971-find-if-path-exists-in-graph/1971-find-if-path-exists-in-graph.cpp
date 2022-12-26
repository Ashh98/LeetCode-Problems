class Solution {
public:
    void dfs(int node, int& des, vector<int>& flag, vector<vector<int>>& adjList, bool& result) {
        for (auto& i : adjList[node]) {
            if (flag[i] == 0 && i == des) result = true;
            if (flag[i] == -1) {
                flag[i] = 0;
                if (i == des) result = true;
                dfs(i, des, flag, adjList, result);
            }
        }
        
        flag[node] = 1;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (edges.size() == 0 && n == 1) return true;
        
        vector<vector<int>> adjList(n);
        vector<int> flag(n, -1);
        bool result = false;
        
        for (auto& i : edges) {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }
        
        flag[source] = 0;
        dfs(source, destination, flag, adjList, result);
        
        return result;
    }
};