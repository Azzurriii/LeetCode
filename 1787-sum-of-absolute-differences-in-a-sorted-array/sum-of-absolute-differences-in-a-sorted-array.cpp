class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        
        int prefixSum = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
        }

        int suffixSum = 0;
        for (int i = 0; i < n; i++) {
            res[i] = (2 * i - n) * nums[i] + prefixSum - 2 * suffixSum;
            suffixSum += nums[i];
        }

        return res;
    }
};
auto speedup = cin.tie(NULL)->sync_with_stdio(false);