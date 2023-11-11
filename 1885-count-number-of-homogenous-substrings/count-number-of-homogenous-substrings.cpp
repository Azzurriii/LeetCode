class Solution {
public:
    int countHomogenous(const string& s) {
        int res{};
        for (size_t k = 0, i = 1; i <= s.size(); ++i)
            if (s[i] != s[k]) res = (res + (i - k) * (i - k + 1) / 2) % 1'000'000'007, k = i;
        return res;
    }
};