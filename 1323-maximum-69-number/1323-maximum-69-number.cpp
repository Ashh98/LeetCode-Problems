class Solution {
public:
    int maximum69Number (int num) {
        int tmp = num;
        int newNum = 0;
        int div;
        if (num >= 10) div = 10;
        else div = 1;
        while (tmp >= 10) {
            tmp = num / div;
            if (tmp >= 10) div = div * 10;
            else break;
        }
        
        int divTest = div;
        tmp = num;
        while (divTest != 0) {
            if (tmp > 10) newNum = newNum + (divTest * (tmp%((tmp/10)*10)));
            else newNum = newNum + tmp;
            tmp = tmp/10;
            divTest = divTest/10;
        }
        
        divTest = div;
        tmp = newNum;
        newNum = 0;
        int countOfSix = 0;
        while (divTest != 0) {
            if (tmp > 10) {
                if ( (tmp%((tmp/10)*10)) == 6 & countOfSix == 0) {
                    countOfSix++;
                    newNum = newNum + (divTest * 9);
                } else newNum = newNum + (divTest * (tmp%((tmp/10)*10)));
            } else {
                if (tmp == 6 && countOfSix == 0) newNum = newNum + 9;
                else newNum = newNum + tmp;
            }
            tmp = tmp/10;
            divTest = divTest/10;
        }
        
        return newNum;
    }
};