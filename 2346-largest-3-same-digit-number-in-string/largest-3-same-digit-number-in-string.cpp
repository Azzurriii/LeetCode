struct Solution {
    string largestGoodInteger(string_view num) {
        for (string_view sv : {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"})
            if (num.find(sv) != num.npos) return string(sv);
        return {};
    }
};

auto speedup = cin.tie(NULL)->sync_with_stdio(false);