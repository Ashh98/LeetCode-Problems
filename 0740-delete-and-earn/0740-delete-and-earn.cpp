class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int earn1=0, earn2=0;
        int curearn=0; int temp;
        unordered_map<int, int> ump;
        for (auto& i : nums) {
            if (ump.find(i) != ump.end()) ump[i]++;
            else ump[i]=1;
        }
        auto it = unique(nums.begin(), nums.end()); 
        nums.erase(it, nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            curearn = nums[i] * ump[nums[i]];
            
            if (i > 0 && nums[i] == nums[i-1]+1) {
                temp = earn2;
                earn2 = max(curearn+earn1, earn2);
                earn1 = temp;
            } else {
                temp = earn2;
                earn2 = earn2+curearn;
                earn1=temp;
            }
        }
        return earn2;
    }
};