class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int res = nums[k], min_i = nums[k], i = k, j = k, n = nums.size();
        while(i > 0 || j < n - 1)
        {
            if( i == 0) j++;
            else if(j == n - 1) i--;
            else if(nums[i - 1] <  nums[j + 1]) j++;
            else i--;
            min_i = min(min_i, min(nums[i], nums[j]));
            res = max(res, min_i*(j - i + 1));
        }
        return res;
    }
};