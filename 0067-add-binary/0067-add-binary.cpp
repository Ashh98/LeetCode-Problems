class Solution {
public:
    string addBinary(string a, string b) {
        string res; string x;
        int carry = 0;
        if (a.size() > b.size()) {
            for (int i = 0; i < a.size()-b.size(); i++) {
                x.push_back('0');
            }
            for (int i = 0; i < b.size(); i++) {
                x.push_back(b[i]);
            }
            
            for (int i = a.size()-1; i >= 0; i--) {
                if (x[i] == '1' && a[i] == '1') {
                    if (carry) {
                        res.push_back('1');
                        carry = 1;
                    } else {
                        res.push_back('0');
                        carry = 1;
                    }
                } else if (x[i] == '1' || a[i] == '1') {
                    if (carry) {
                        res.push_back('0');
                        carry = 1;
                    } else res.push_back('1');
                } else {
                    if (carry) {
                        res.push_back('1');
                        carry = 0;
                    } else res.push_back('0');
                }
            }
            if (carry) res.push_back('1');
            reverse(res.begin(), res.end());
        } else if (b.size() > a.size()) {
            for (int i = 0; i < b.size()-a.size(); i++) {
                x.push_back('0');
            }
            for (int i = 0; i < a.size(); i++) {
                x.push_back(a[i]);
            }
            
            for (int i = b.size()-1; i >= 0; i--) {
                if (b[i] == '1' && x[i] == '1') {
                    if (carry) {
                        res.push_back('1');
                        carry = 1;
                    } else {
                        res.push_back('0');
                        carry = 1;
                    }
                } else if (b[i] == '1' || x[i] == '1') {
                    if (carry) {
                        res.push_back('0');
                        carry = 1;
                    } else res.push_back('1');
                } else {
                    if (carry) {
                        res.push_back('1');
                        carry = 0;
                    } else res.push_back('0');
                }
            }
            if (carry) res.push_back('1');
            reverse(res.begin(), res.end());
        } else {
            for (int i = a.size()-1; i >= 0; i--) {
                if (b[i] == '1' && a[i] == '1') {
                    if (carry) {
                        res.push_back('1');
                        carry = 1;
                    } else {
                        res.push_back('0');
                        carry = 1;
                    }
                } else if (b[i] == '1' || a[i] == '1') {
                    if (carry) {
                        res.push_back('0');
                        carry = 1;
                    } else res.push_back('1');
                } else {
                    if (carry) {
                        res.push_back('1');
                        carry = 0;
                    } else res.push_back('0');
                }
            }
            if (carry) res.push_back('1');
            reverse(res.begin(), res.end());
        }
        return res;
    } 
};