class Solution {
public:
    int getXOR(vector<int>& arr, int f, int l) {
        int xor_res = 0;
        for (int i = f; i <= l; i++) {
            xor_res ^= arr[i];
        }
        return xor_res;
    }
    int countTriplets(vector<int>& arr) {
        int c = 0, a = 0, b = 0;
        for (int i = 1; i < arr.size(); i++) {
            for (int j = 0; j < arr.size()-i; j++) {
                if (getXOR(arr, j, j+i) == 0) c += i;
            }
        }
        return c;
    }
};