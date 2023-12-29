class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() < d) return -1;
        if (jobDifficulty.size() == d)
            return accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);

        int dp[10][300] = {jobDifficulty[0]};
        int n = jobDifficulty.size();
        
        for (int j = 1; j < n; ++j) {
            dp[0][j] = max(dp[0][j-1], jobDifficulty[j]);
        }

        for (int i = 1; i < d; ++i) {
            dp[i][0] = jobDifficulty[0];

            for (int j = 1; j < n; ++j) {
                int job = jobDifficulty[j];
                dp[i][j] = dp[i-1][j-1] + job;
                for (int l = j-1; l >= i; --l) {
                    job = max(job, jobDifficulty[l]);
                    dp[i][j] = min(dp[i][j], dp[i-1][l-1] + job);
                }
            }
        }
        return dp[d-1][n-1];
    }
};
auto speedup = cin.tie(NULL) -> sync_with_stdio(false);