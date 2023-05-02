class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg_count = 0;
        for (auto& i : nums) {
            if (i < 0) neg_count++;
            else if (i == 0) return 0;
        }
        
        if (!(neg_count%2)) return 1;
        else return -1;
    }
};