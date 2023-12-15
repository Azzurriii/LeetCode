class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int length = 1;
        for(int i = 1; i < nums.size(); ++i){
            int maxVal = 0;
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j])
                    maxVal = max(maxVal, dp[j]);
            }
            dp[i] = maxVal + 1;
            length = max(dp[i], length);
        }
        return length;
    }
};