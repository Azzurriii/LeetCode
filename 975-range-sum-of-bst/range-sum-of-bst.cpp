class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int res = 0;
        if(!root) return res;
        else{
            if(root->val >= low && root->val <= high){
                res += root->val;
            }
            res += rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
            return res;
        }
    }
};