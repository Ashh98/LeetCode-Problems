class Solution {
public:

    void dfs(vector<vector<int>>& rooms, stack<int>& s, vector<int>& flag) {
        int node = s.top();
        for (auto& i : rooms[node]) {
            if (flag[i] == -1) {
                s.push(i);
                flag[i] = 0;
                dfs(rooms, s, flag);
            }
        }
        flag[s.top()] = 1;
        s.pop();
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> s;
        vector<int> flag(rooms.size(), -1);
        s.push(0);
        flag[0] = 0;
        dfs(rooms, s, flag);
        for (auto& i : flag) {
            if (i != 1) return false;
        }
        return true;
    }

    
};