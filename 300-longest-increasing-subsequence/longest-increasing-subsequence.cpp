class Solution {
public:
    // int lengthOfLIS(vector<int>& nums) {
    //     vector<int> dp(nums.size(), 1);
    //     int length = 1;
    //     for(int i = 1; i < nums.size(); ++i){
    //         int maxVal = 0;
    //         for(int j = 0; j < i; ++j){
    //             if(nums[i] > nums[j])
    //                 maxVal = max(maxVal, dp[j]);
    //         }
    //         dp[i] = maxVal + 1;
    //         length = max(dp[i], length);
    //     }
    //     return length;
    // }
    int lengthOfLIS(vector<int> nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int len = 0;

        for (int num : nums) {
            int left = 0, right = len;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (dp[mid] < num) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            dp[left] = num;
            if (left == len) {
                len++;
            }
        }

        return len;
    }
};