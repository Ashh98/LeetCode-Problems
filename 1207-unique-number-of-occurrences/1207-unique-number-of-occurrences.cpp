class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> ump;
        unordered_map<int, int> ump1;
        bool flag;
        for (int i = 0; i < arr.size(); i++) {
            if (ump.find(arr[i]) != ump.end()) {
                ump[arr[i]]++;
            } else {
                ump.insert({arr[i], 1});
            }
        }
        for (auto i: ump) {
            if (ump1.find(i.second) != ump1.end()) {
                flag = false;
                break;
            } else {
                ump1.insert({i.second, i.first});
                flag = true;
            }
        }
        return flag;
    }
};