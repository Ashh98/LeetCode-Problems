class Solution {
public:
    int numberOfSteps(int num) {
        int c = 0;
        while (num) {
            if (!(num%2)) num = num/2;
            else num--;
            c++;
        }
        return c;
    }
};