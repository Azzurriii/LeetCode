class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root == nullptr)
            return "";
        string res = to_string(root->val);
        if(root->left)
          res += "(" + tree2str(root->left) + ")";
        if(root->right){
          if(!root->left)
            res += "()";
          res += "(" + tree2str(root->right) + ")";
        }   
        return res;
    }
};