class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, pair<int, int>> ump;
        for (auto& i : paths) {
            for (int j = 0; j <= 1; j++) {
                if (ump.find(i[j]) != ump.end()) {
                    ump[i[j]].first++;
                } else {
                    ump[i[j]] = {1, j};
                }
            }
        }
        
        for (auto& i : ump) {
            if (i.second.first == 1 && i.second.second == 1) return i.first;
        }
        
        return "";
    }
};