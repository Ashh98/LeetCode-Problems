class Solution {
public:
    int getXOR(vector<int>& arr) {
        int xor_res = 0;
        for (int i = 0; i < arr.size(); i++) {
            xor_res ^= arr[i];
        }
        return xor_res;
    }
    int countTriplets(vector<int>& arr) {
        int c = 0, a = 0, b = 0; int i = 0;
        int xor_res = getXOR(arr), tmp_res = 0;
        for (int j = arr.size()-1; j >= i; j--) {
            if (j+1 <= arr.size()-1) xor_res ^= arr[j+1];
            tmp_res = xor_res;
            for (int i = 0; i < j; i++) {
                if (i-1 >= 0) tmp_res ^= arr[i-1];
                if (tmp_res == 0) c += j-i;
            }
        }
        return c;
    }
};