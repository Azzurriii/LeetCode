class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        auto rev = [](int n) {
            int res = 0;
            for (; n; n /= 10) res = res * 10 + n % 10;
            return res;
        };
        unordered_map<int, int> f;
        for (int n : nums) ++f[n - rev(n)];
        int res{};
        for (auto& [k, v] : f) res = (res + static_cast<int64_t>(v) * (v - 1) / 2) % 1'000'000'007;
        return res;
    }
};
