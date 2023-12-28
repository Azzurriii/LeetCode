class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX / 2));

        dp[0][0] = 0;  // Base case

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j > 0) {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                int same = 0;
                int diff = 0;

                for (int l = i; l >= 1; l--) {
                    if (s[l - 1] == s[i - 1]) {
                        same++;
                    } else {
                        diff++;
                    }

                    if (diff > j) {
                        break;
                    }

                    dp[i][j] = min(dp[i][j], dp[l - 1][j - diff] + 1 + (same >= 100 ? 3 : same >= 10 ? 2 : same >= 2 ? 1 : 0));
                }
            }
        }

        int result = INT_MAX;
        for (int j = 0; j <= k; j++) {
            result = min(result, dp[n][j]);
        }

        return result;
    }
};
auto speedup = cin.tie(NULL) -> sync_with_stdio(false);