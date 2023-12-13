class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int special = 0;
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 1){
                  rows[i]++;
                  cols[j]++;
                }
            }
        }
        for(int i = 0; i < m; i++)
        {
            if(rows[i] != 1) continue;
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 1 && cols[j] == 1){
                    special++;
                }
            }
        }

        return special;
    }
};