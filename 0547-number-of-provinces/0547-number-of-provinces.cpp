class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, stack<int>& s, vector<int>& flag) {
        for (int i = 0; i < isConnected[s.top()].size(); i++) {
            if (isConnected[s.top()][i] != 0) {
                if (flag[i] == -1) {
                    flag[i] = 0;
                    s.push(i);
                    dfs(isConnected, s, flag);
                }
            }
        }

        flag[s.top()] = 1;
        s.pop();
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        stack<int> s;
        vector<int> flag(isConnected.size(), -1);
        int c = 0;
        int i;

        while (true) {
            i = -1;
            for (int j = 0; j < flag.size(); j++) {
                if (flag[j] == -1) i = j; 
            }
            if (i == -1)  break;

            if (flag[i] == -1)  {
                s.push(i);
                flag[i] = 0;
                dfs(isConnected, s, flag);
                c++;
            }
            //cout << i << endl;
        }

        return c;
    }
};