class Solution {
private:
    vector<TreeNode*> allTrees(int l, int r, vector<TreeNode*> dp[][10]){
        if(l > r) return {nullptr};
        if(l == r) return {new TreeNode(l)};
        if(dp[l][r].size() != 0) return dp[l][r];

        for(int k=l; k<=r; k++){

            vector<TreeNode*> left_bst = allTrees(l,k-1,dp);
            vector<TreeNode*> right_bst = allTrees(k+1,r,dp);

            int i = left_bst.size() - 1;

            while(i > -1){
                int j = right_bst.size() - 1; 
                while(j > -1){
                    TreeNode* root = new TreeNode(k);
                    root->left = left_bst[i];
                    root->right = right_bst[j];
                    dp[l][r].push_back(root);
                    j--;
                }
                i--;
            }
        }
        
        return dp[l][r];
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> dp[10][10];
        return allTrees(1,n,dp);
    }
};