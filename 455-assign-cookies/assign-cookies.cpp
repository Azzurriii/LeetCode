class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        for (int num: s) {
            if (ans == g.size()) 
                break;
            if (num >= g[ans]) 
                ans++;
        }
        return ans;
    }
};