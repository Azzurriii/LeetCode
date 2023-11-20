struct Solution {
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int res{};
        int ig = 0, ip = 0, im = 0;
        for (int i = 0; auto& s : garbage) {
            res += s.size();
            if (s.find('G') != s.npos) ig = i;
            if (s.find('P') != s.npos) ip = i;
            if (s.find('M') != s.npos) im = i;
            ++i;
        }
        return res + accumulate(begin(travel), begin(travel) + ig, 0)
                   + accumulate(begin(travel), begin(travel) + ip, 0)
                   + accumulate(begin(travel), begin(travel) + im, 0);
    }
};

auto speedup = cin.tie(NULL)->sync_with_stdio(false);