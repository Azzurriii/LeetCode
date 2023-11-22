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
        bool isNullBefore = false;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* curNode = q.front();
            q.pop();

            if(!curNode)
                isNullBefore = true;
            else{
                if(isNullBefore)
                    return false;
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }

        return true;
    }
};