class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else if (j < i || i * k < j) {
                    dp[i][j] = 0;
                } else {
                    for (int x = 1; x <= k; x++) {
                        if (j >= x) {
                            dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
                        }
                    }
                }
            }
        }

        return dp[n][target];
    }
};