class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long l = 0, r = 1;
        long long ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                k -= (i - l) * (nums[i] - nums[i - 1]);
            }
            while (k < 0) {
                k += nums[i] - nums[l];
                l += 1;
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};