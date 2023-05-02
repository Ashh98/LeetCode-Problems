class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string word1_conc = "";
        string word2_conc = "";
        
        for (auto& i : word1) {
            for (auto& j : i) {
                word1_conc.push_back(j);
            }
        }
        
        for (auto& i : word2) {
            for (auto& j : i) {
                word2_conc.push_back(j);
            }
        }
        
        return (word1_conc == word2_conc);
    }
};