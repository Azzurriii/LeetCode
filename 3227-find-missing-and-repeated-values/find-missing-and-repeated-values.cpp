class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid){
    int n = grid.size();
    vector<int> ans(2);
    vector<int> count(n * n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = grid[i][j];
            count[num]++;
            if (count[num] == 2) {
                ans[0] = num; // Repeating number
            }
        }
    }
    
    for (int i = 1; i <= n * n; i++) {
        if (count[i] == 0) {
            ans[1] = i; // Missing number
            break;
        }
    }
    
    return ans;
}
};