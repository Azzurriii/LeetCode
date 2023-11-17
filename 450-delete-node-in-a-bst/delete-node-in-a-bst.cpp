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
    TreeNode* deleteNode(TreeNode* root, int key) {
         // Base case
    if (!root)
        return root;
    // Tìm vị trí node cần xóa
    if (root->val > key)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }
    else if (root->val < key)
    {
        root->right = deleteNode(root->right, key);
        return root;
    }
    // Nếu có 1 con bị khuyết
    if (root->left == nullptr)
    {
        TreeNode *temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == nullptr)
    {
        TreeNode *temp = root->left;
        delete root;
        return temp;
    }
    // Nếu có cả 2 con
    else
    {
        TreeNode *succParrent = root;
        // Tìm node thay thế.
        TreeNode *succ = root->right;
        while (succ->left)
        {
            succParrent = succ;
            succ = succ->left;
        }
        
        if (succParrent != root)
            succParrent->left = succ->right;
        else
            succParrent->right = succ->right;

        // Sao cheps successor data vào root
        root->val = succ->val;
        delete succ;
        return root;
    }
    }
};