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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool nullFound = false;

        while (!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();

            if (curNode) {
                if (nullFound) {
                    // If a null node has been found earlier, this is not a complete tree
                    return false;
                }

                q.push(curNode->left);
                q.push(curNode->right);
            } else {
                // Mark that a null node has been found
                nullFound = true;
            }
        }

        return true;
    }
};
