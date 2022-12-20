class Solution {
public:
    int maximumValue(vector<string>& strs) {
        bool status; int count = 0;
        for (auto& i : strs) {
            status = false;
            for (auto& j : i) {
                if (isalpha(j)) status = true;
            }
            if (status) {
                if (i.size() > count) count = i.size();
            } else {
                if (stoi(i) > count) count = stoi(i);
            }
        }
        
        return count;
    }
};