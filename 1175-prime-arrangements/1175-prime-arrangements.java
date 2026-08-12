class Solution {
    public int numPrimeArrangements(int n) {
        int M = 1000000007;
        boolean[] prime = new boolean[n+1];
        java.util.Arrays.fill(prime, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        int countPrimes = 0;
        for (int i = 2; i <= n; i++) {
            if (prime[i]) countPrimes++;
        }
        
        long ans = 1;
        for (int i = 1; i <= countPrimes; i++) {
            ans = (ans * i) % M;
        }
        for (int i = 1; i <= n - countPrimes; i++) {
            ans = (ans * i) % M;
        }
        return (int) ans;
    }
}