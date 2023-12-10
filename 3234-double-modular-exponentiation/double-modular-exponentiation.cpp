class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> goodIndices;
        int n = variables.size();

        for (int i = 0; i < n; i++) {
            int ai = variables[i][0];
            int bi = variables[i][1];
            int ci = variables[i][2];
            int mi = variables[i][3];

            int base = 1;
            for (int j = 0; j < bi; ++j) {
                base = (base * ai) % 10;
            }
            int formula_result = 1;
            for (int j = 0; j < ci; ++j) {
                formula_result = (formula_result * base) % mi;
            }
            if (formula_result == target) {
                goodIndices.push_back(i);
            }
        }

        return goodIndices;
    }
};