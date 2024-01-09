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
    bool leafSimilar(TreeNode* root1, TreeNode* root2){
        vector<int> leaves1;
        vector<int> leaves2;
        function<void(TreeNode*, vector<int>&)> dfs = [&](TreeNode* root, vector<int>& leaves) {
            if (!root) {
                return;
            }
            if (!root->left && !root->right) {
                leaves.push_back(root->val);
                return;
            }
            dfs(root->left, leaves);
            dfs(root->right, leaves);
        };
        dfs(root1, leaves1);
        dfs(root2, leaves2);
        return leaves1 == leaves2;
    }
};