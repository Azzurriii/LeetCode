class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        int count = 0;
        for(int l = 0, r =0; r < n; ++r) {
            int val = nums[r];
            freq[val]++;
            while(freq[val] > k) freq[nums[l++]]--;
            count = max(count, r - l +1);
        }
        return count;
    }
};