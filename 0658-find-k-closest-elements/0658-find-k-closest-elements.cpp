class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        vector<int> absDif(arr.size());
        int min = INT_MAX; int minInd = 0;
        for (int i = 0; i < arr.size(); i++) {
            absDif[i] = abs(arr[i] - x);
        }
        for (int i = 0; i < absDif.size(); i++) {
            if (absDif[i] < min) {
                min = absDif[i];
                minInd = i;
            }
        }
        
        int i = minInd, j = minInd;
        int c = 0;
        while (c < k) {
            if (i >= 0 && j < arr.size()) {
                if (absDif[i] < absDif[j]) {
                    res.push_back(arr[i]);
                    i--;
                    c++;
                } else if (absDif[i] > absDif[j]) {
                    res.push_back(arr[j]);
                    j++;
                    c++;
                } else {
                    if (arr[i] < arr[j]) {
                        res.push_back(arr[i]);
                        i--;
                    } else if (arr[i] > arr[j]) {
                        res.push_back(arr[j]);
                        j++;
                    } else {
                        res.push_back(arr[i]);
                        i--; j++;
                    }
                    c++;
                }
            } else if (i >= 0) {
                res.push_back(arr[i]);
                i--;
                c++;
            } else {
                res.push_back(arr[j]);
                j++;
                c++;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};