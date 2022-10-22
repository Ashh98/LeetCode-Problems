#include <unordered_map>
#include <string.h>
class Solution {
public:
    unordered_map<string,int> ump{
        {"I", 1},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"X", 10},
        {"XL", 40},
        {"L", 50},
        {"XC", 90},
        {"C", 100},
        {"CD", 400},
        {"D", 500},
        {"CM", 900},
        {"M", 1000},
    };
    int romanToInt(string s) {
        int sum = 0;
        while (s.length() != 0) {
            if (ump.find(s.substr(0,2)) == ump.end()) {
                sum = sum + ump[s.substr(0,1)];
                s.erase(0,1);
            } else {
                sum = sum + ump[s.substr(0,2)];
                s.erase(0,2);
            }
        }
        return sum;
    }
};