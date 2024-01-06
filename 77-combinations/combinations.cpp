class Solution {
public:
    vector<vector<int>> combine(int n, int k){
    vector<vector<int>> ans;
    vector<int> temp;
    for(int i = 1; i <= n; i++){
        temp.push_back(i);
    }
    for(int i = 0; i < temp.size(); i++){
        vector<int> temp2;
        temp2.push_back(temp[i]);
        ans.push_back(temp2);
    }
    for(int i = 1; i < k; i++){
        vector<vector<int>> temp3;
        for(int j = 0; j < ans.size(); j++){
            for(int l = ans[j][ans[j].size() - 1] + 1; l <= n; l++){
                vector<int> temp4 = ans[j];
                temp4.push_back(l);
                temp3.push_back(temp4);
            }
        }
        ans = temp3;
    }
    return ans;
}
};