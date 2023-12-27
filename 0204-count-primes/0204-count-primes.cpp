class Solution {
public:
    int countPrimes(int n) {
        if (n == 0) return 0;
        vector<int> primes(n+1, true);
        primes[0] = 0; primes[1] = 0;
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (primes[i]) {
                count++;
                for (int j = 2*i; j < n; j+=i) {
                    primes[j]=0;
                }
            }
        }
        return count;
    }
};