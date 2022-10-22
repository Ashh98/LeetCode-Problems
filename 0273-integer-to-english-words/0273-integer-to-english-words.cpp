class Solution {
public:
    string numberToWords(int num) {
        string snum = to_string(num);
        reverse(snum.begin(), snum.end()); 
        int numSize = snum.size();
        unordered_map<char, string> units = {
            {'1', "One"},
            {'2', "Two"},
            {'3', "Three"},
            {'4', "Four"},
            {'5', "Five"},
            {'6', "Six"},
            {'7', "Seven"},
            {'8', "Eight"},
            {'9', "Nine"}
        };
        unordered_map<char, string> ten_to_twe = {
            {'1', "Eleven"},
            {'2', "Twelve"},
            {'3', "Thirteen"},
            {'4', "Fourteen"},
            {'5', "Fifteen"},
            {'6', "Sixteen"},
            {'7', "Seventeen"},
            {'8', "Eighteen"},
            {'9', "Nineteen"}
        };
        unordered_map<char, string> tenths = {
            {'2', "Twenty"},
            {'3', "Thirty"},
            {'4', "Forty"},
            {'5', "Fifty"},
            {'6', "Sixty"},
            {'7', "Seventy"},
            {'8', "Eighty"},
            {'9', "Ninety"}
        };
        vector<string> form(10,"");
        string res = "";
        form[0] = "";
        form[1] = "";
        form[2] = " Hundred";
        form[3] = " Thousand";
        form[4] = "";
        form[5] = " Hundred";
        form[6] = " Million";
        form[7] = "";
        form[8] = " Hundred";
        form[9] = " Billion";
        for (int i = 0; i < numSize; i++) {
            if (snum[i] == '0' && numSize == 1) {
                form[i] = "Zero";
                break;
            } else if (snum[i] == '1' && i % 3 == 1) {
                if (snum[i-1] == '0') form[i] = "Ten";
                else form[i] = ten_to_twe[snum[i-1]];
            } else if (i % 3 == 0 && snum[i+1] != '1') {
                form[i] = units[snum[i]] + form[i];
            } else if (i % 3 == 1) {
                form[i] = tenths[snum[i]] + form[i];
            } else if (i % 3 == 2) {
                form[i] = units[snum[i]] + form[i];
            }
        }
                
        if (form[2] == " Hundred") form[2] = "";
        if (form[3] == " Thousand") {
            if (form[4] == "" && form[5] == " Hundred") form[3] = "";
        } 
        if (form[5] == " Hundred") form[5] = "";
        if (form[6] == " Million") {
            if (form[7] == "" && form[8] == " Hundred") form[6] = "";
        } 
        if (form[8] == " Hundred") form[8] = "";
        
        for (int i = numSize-1; i >= 0; i--) {
            if (form[i] == "") res = res + form[i];
            else if (i == numSize-1) res = res + form[i];
            else if (form[i] == " Hundred" || form[i] == " Thousand" || form[i] == " Million") res = res + form[i];
            else res = res + " " + form[i];
        }
        
        return res;
    }
};