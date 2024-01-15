class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>> const& matches) {
        vector<vector<int>> res(2);
        unordered_map<int, int> counter;
        for (auto const& m : matches)
            counter[m[0]], counter[m[1]]++;
        for (auto const& it : counter) 
            if (it.second <= 1) res[it.second].emplace_back(it.first);
        sort(begin(res[0]), end(res[0]));
        sort(begin(res[1]), end(res[1]));
        return res;
    }
};