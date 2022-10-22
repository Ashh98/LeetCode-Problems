class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool flag = false;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
                flag = true;
                if (i-1 == -1) {
                    digits.insert(digits.begin(), 1);
                }
            } else {
                digits[i] = digits[i] + 1;
                flag = false;
            }
            
            if (flag == false) {
                break;
            }
        }
        return digits;
    }
};