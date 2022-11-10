class Solution {
public:
    vector<int> circle;
    vector<int> ctrl;
    int nCtrl = 0;
    
    void setParams(int n) {
        for (int i = 1; i <= n; i++) {
            circle.push_back(i);
            ctrl.push_back(1);
        }
        nCtrl = ctrl.size();
    }
    int findTheWinner(int k, int ind, vector<int> circle, vector<int> ctrl) {
        int res;
        if (nCtrl == 1) return circle[ind];
        else {
            int c = k;
            while (c > 0) {
                if (ctrl[ind] == 1) c--;
                if (c > 0) ind = (ind+1) % circle.size();
            }
            ctrl[ind] = 0;
            while (true) {
                if (ctrl[(ind+1) % circle.size()] == 1) {
                    ind = (ind+1) % circle.size();
                    break;
                } else ind = (ind+1) % circle.size();
            }
            nCtrl--;
            res = findTheWinner(k, ind, circle, ctrl);
        }
        return res;
    }
    int findTheWinner(int n, int k) {
        setParams(n);
        return findTheWinner(k, 0, circle, ctrl);
    }
};