class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        vector<vector<int>>dp;
        dp.resize(n + 1, vector<int>(target + 1, 0));
        dp[0].resize(min(k + 1, target + 1), 1);
        fill(dp[0].begin() + 1, dp[0].end(), 1);
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) % mod;
                if (j > k) {
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - 1 - k] + mod) % mod;
                }
            }
        }
        return dp[n - 1][target];
    }
};