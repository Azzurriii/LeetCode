class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int r = 0;
        int l = 0;
        int n = nums.size();
        vector<int> res(n);
        for(int i = 0 ; i < n ; i++){
            r += nums[i];
        }
        for(int i = 0 ; i < n; i++){
            res[i] = r + (2*i - n) * nums[i] - l;
            l += nums[i];
            r -= nums[i];
        }
        return res;
    }
};