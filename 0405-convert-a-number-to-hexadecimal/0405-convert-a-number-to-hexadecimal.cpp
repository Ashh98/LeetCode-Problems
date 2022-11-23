class Solution {
public:
    void reverseStr(string& str) {
        int i = 0, j = str.size()-1;
        char tmp;
        while (i < j) {
            tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
            i++; j--;
        }
    }
    string toHex(long num) {
        if (num == 0) return "0";
        string res;
        unordered_map<int, char> ump = {
            {1, '1'},
            {2, '2'},
            {3, '3'},
            {4, '4'},
            {5, '5'},
            {6, '6'},
            {7, '7'},
            {8, '8'},
            {9, '9'},
            {10, 'a'},
            {11, 'b'},
            {12, 'c'},
            {13, 'd'},
            {14, 'e'},
            {15, 'f'}
        };
        
        if (num < 0) {
            num = 4294967296 + num;
        }
        
        while (num) {
            if (num%16) res.push_back(ump[num%16]);
            else res.push_back('0');
            num = num / 16;
        }
        reverseStr(res);
        return res;
    }
};