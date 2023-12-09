class Solution {
private:
    void LNR(TreeNode* root, vector<int>& res)
    {
        if(root){
            LNR(root->left, res);
            res.push_back(root->val);
            LNR(root->right, res);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        LNR(root, res);
        return res;
    }
};