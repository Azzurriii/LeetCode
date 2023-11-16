class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;

        // Use Morris Traversal to perform in-order traversal without recursion and with constant space
        while (root) {
            if (root->left) {
                // Find the inorder predecessor of the current root
                TreeNode* predecessor = root->left;
                while (predecessor->right && predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                if (!predecessor->right) {
                    // Set the threaded link to the current root
                    predecessor->right = root;
                    root = root->left;
                } else {
                    // Revert the threaded link and visit the current root
                    predecessor->right = nullptr;

                    if (prev && prev->val > root->val) {
                        if (!first) {
                            first = prev;
                        }
                        second = root;
                    }

                    prev = root;
                    root = root->right;
                }
            } else {
                if (prev && prev->val > root->val) {
                    if (!first) {
                        first = prev;
                    }
                    second = root;
                }

                prev = root;
                root = root->right;
            }
        }

        // Swap the values of the two misplaced nodes
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};
