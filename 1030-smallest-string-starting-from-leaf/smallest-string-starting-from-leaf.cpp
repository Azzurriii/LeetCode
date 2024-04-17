/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, string s, string& ans) {
        if (!root) {
            return;
        }
        s.push_back('a' + root->val);
        if (!root->left && !root->right) {
            reverse(s.begin(), s.end());
            if (ans.empty() || s < ans) {
                ans = s;
            }
            reverse(s.begin(), s.end());
        }
        dfs(root->left, s, ans);
        dfs(root->right, s, ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        string s = "";
        dfs(root, s, ans);
        return ans;
    }
};