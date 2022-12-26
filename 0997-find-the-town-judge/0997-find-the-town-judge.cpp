class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1 && trust.size() == 0) return 1;
        vector<int> indeg(n+1, 0);
        vector<int> outdeg(n+1, 0);

        
        for (auto& i : trust) {
            indeg[i[1]]++;
            outdeg[i[0]]++;
        }
        
        for (int i = 0 ; i < indeg.size(); i++) {
            if (indeg[i] == n-1) {
                if(outdeg[i] == 0) return i;
            }
        }
        
        return -1;
    }
};