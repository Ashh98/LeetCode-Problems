class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        else if (n == 2) return true;
        else {
            for (int i = 2; i < n; i++) {
                if (n%i == 0) return false;
            }
        }
        return true;
    }
    
    int countOnes(int n) {
        int c = 0;
        while (n) {
            if (n%2 == 1) c++;
            n >>= 1;
        }
        return c;
    }
    int countPrimeSetBits(int left, int right) {
        int c = 0;
        for (int i = left; i <= right; i++) {
            if (isPrime(countOnes(i))) c++;
        }
        return c;
    }
};