class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int i = 1;
        int n = points.size();
        int res = 0;
        for(i=1;i<n;i++){
            int y2 = points[i][1];
            int y1 = points[i-1][1];
            int x2 = points[i][0];
            int x1 = points[i-1][0];
            int difY = abs(y2-y1);
            int difX = abs(x2-x1);
            res += max(difY,difX);
        }
        

        return res;
    }
};
auto speedup = cin.tie(NULL) -> sync_with_stdio(false);