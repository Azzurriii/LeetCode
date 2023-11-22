class Solution {
   public:
    vector<int> findDiagonalOrder(vector<vector<int>> const& nums) {
        vector<tuple<size_t, size_t, size_t>> idx;
        //  (r + c) * (r + c + 1) / 2 => sum of elements of previous rays
        for (size_t r = 0; r < nums.size(); ++r)
            for (size_t c = 0; c < nums[r].size(); ++c)
                idx.emplace_back((r + c) * (r + c + 1) / 2 + c, r, c);
        sort(begin(idx), end(idx));
        vector<int> res;
        for (auto [_, r, c] : idx) res.emplace_back(nums[r][c]);
        return res;
    }
};