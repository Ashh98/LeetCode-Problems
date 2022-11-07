class Solution {
public:
    int minTimeToType(string word) {
        char ptr = 'a';
        int time = word.size();
        
        for (auto& i: word) {
            time = time + min(abs(i - ptr), 26-abs(i - ptr));
            ptr = i;
        }
        return time;
    }
};