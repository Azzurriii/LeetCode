class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
            for (int num: s) {
            if (i == g.size()) 
                break;
            if (num >= g[i]) 
                i++;
        }
        return i;
    }
};