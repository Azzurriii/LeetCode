class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        vector<vector<int>>dp(n + 1, vector<int>(target + 1, 0));
        for (int j = 1; j <= k && j <= target; j++) {
            dp[0][j] = 1;
        }
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
auto speedup = cin.tie(NULL) -> sync_with_stdio(false);