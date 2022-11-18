class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> arr(n, 0);
        int res = start;
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = start + 2 * i;
            if (i > 0) res = res ^ arr[i];
        }
        return res;
    }
};