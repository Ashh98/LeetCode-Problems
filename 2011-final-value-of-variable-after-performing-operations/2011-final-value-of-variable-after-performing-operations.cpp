class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int result = 0;
        for (auto& op : operations) {
            if (op[0] == '-' || op[1] == '-') result--;
            else result++;
        }
        return result;
    }
};