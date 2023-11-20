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
private:
    bool DFSCheck(TreeNode* leftBranch, TreeNode* rightBranch)
    {
        if(!leftBranch && !rightBranch)
            return true;
        if(!leftBranch || !rightBranch)
            return false;
        
        return DFSCheck(leftBranch->left, rightBranch->right)
                && DFSCheck(leftBranch->right, rightBranch->left)
                && (leftBranch->val == rightBranch->val);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return DFSCheck(root->left, root->right);     
    }
};