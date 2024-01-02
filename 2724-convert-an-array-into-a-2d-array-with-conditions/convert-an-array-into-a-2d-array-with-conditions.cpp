class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int col = 0;
        map<int, int> check;
        for (int i = 0; i < nums.size(); i++) {
            check[nums[i]]++;
            col = max(col, check[nums[i]]);
        }
        vector<vector<int>> ans(col);
        for (int i = 0; i < nums.size(); i++) {
            ans[check[nums[i]] - 1].push_back(nums[i]);
            check[nums[i]]--;
        }
        return ans;
    }
};