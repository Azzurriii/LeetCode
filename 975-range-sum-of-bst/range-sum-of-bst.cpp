/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
        auto speedup = cin.tie(NULL)->sync_with_stdio(false);
    }
};
