class Solution {
public:
    
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