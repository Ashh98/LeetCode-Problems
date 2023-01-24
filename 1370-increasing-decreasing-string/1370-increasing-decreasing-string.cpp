class Solution {
public:
    string sortString(string s) {
        unordered_map<char, int> ump;
        int count;
        char track, charMin, charMax;
        bool flag = true;
        string result = "";
        
        for (auto& i : s) {
            if (ump.find(i) != ump.end()) ump[i]++;
            else ump[i] = 1;
        }
        
        
        while (true) {
            track = CHAR_MIN;
            while (true) {
                charMin = CHAR_MAX;
                count = 0;
                for (auto& i : ump) {
                    if (i.first > track && i.second > 0) if (i.first < charMin) charMin = i.first;
                    if (i.second == 0) count++;
                }
                if (charMin == CHAR_MAX) break;
                ump[charMin]--;
                result.push_back(charMin);
                track = charMin;
            }
            
            if (count == ump.size()) break;
            
            track = CHAR_MAX;
            while (true) {
                charMax = CHAR_MIN;
                count = 0;
                for (auto& i : ump) {
                    if (i.first < track && i.second > 0) if (i.first > charMax) charMax = i.first;
                    if (i.second == 0) count++;
                }
                if (charMax == CHAR_MIN) break;
                ump[charMax]--;
                result.push_back(charMax);
                track = charMax;
            }
            
            if (count == ump.size()) break;
        }
        

        return result;
    }
};