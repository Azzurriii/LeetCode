class Solution {
public:
    int knightDialer(int n) {
        const int MOD = 1000000007;
        long a = 1, b = 1, c = 1, d = 1;

        if (n == 1) {
            return 10;
        }

        for (int i = 1; i < n; ++i) {
            long tempA = 2 * b % MOD;
            long tempB = (a + c) % MOD;
            long tempC = (d + 2 * b) % MOD;
            long tempD = 2 * c % MOD;

            a = tempA;
            b = tempB;
            c = tempC;
            d = tempD;
        }

        return (2 * a + 4 * b + 2 * c + d) % MOD;
    }
};
auto speedup = cin.tie(NULL)->sync_with_stdio(false);