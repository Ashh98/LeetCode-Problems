class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> ump;
        int luck_int = -1;
        for (auto& i : arr) {
            if (ump.find(i) != ump.end()) ump[i]++;
            else ump[i] = 1;
        }
        
        for (auto& i : ump) {
            if (i.first == i.second) if (i.first > luck_int) luck_int = i.first;
        }
        
        return luck_int;
    }
};