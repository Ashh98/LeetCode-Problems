class Solution {
public:
    int triangularSum(vector<int>& nums) 
    {
        int idx=0;
        vector<int>temp;
        while(nums.size()>1)
        {
            while(idx < nums.size()-1)
            {
                temp.push_back((nums[idx]+nums[idx+1])%10);
                idx=idx+1;
            }       	
            nums=temp;
            temp.clear();
            idx=0;
        }
        return nums[0];
    }
};