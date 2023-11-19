struct Solution {
    int reductionOperations(vector<int>& nums) {
        uint16_t freq[50'001]{};
        for (int n : nums) ++freq[n];
        return accumulate(begin(freq), end(freq), 0, [i = 0](int res, int cnt) mutable {
            return res += cnt * exchange(i, i + (cnt > 0));
        });
    }
};

auto speedup = cin.tie(NULL)->sync_with_stdio(false);