class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> hash(101, 0);
        int sum = 0;
        
        for (auto& i : nums) {
            hash[i]++;
        }
        
        for (int i = 0; i < hash.size(); i++) {
            if (hash[i] == 1) sum += i;
        }
        
        return sum;
    }
};