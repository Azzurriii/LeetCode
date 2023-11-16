class Solution {
private:
    void NLR(TreeNode* root, vector<int>& res){
        if(root)
        {
            res.push_back(root->val);
            NLR(root->left, res);
            NLR(root->right, res);
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        NLR(root, res);
        return res;
    }
};