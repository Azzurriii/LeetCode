class Solution {
private:
    bool isPseudoPalindromic(const unordered_map<int, int>& freq) {
        int oddCount = 0;
        for (const auto& it : freq) {
            if (it.second % 2 == 1) {
                oddCount++;
                if (oddCount > 1) {
                    return false;
                }
            }
        }
        return true;
    }
    void dfs(TreeNode* node, unordered_map<int, int>& freq, int& fnl) {
        if (node == nullptr) {
            return;
        }
        freq[node->val]++;
        if (node->left == nullptr && node->right == nullptr) {
            if (isPseudoPalindromic(freq)) {
                fnl++;
            }
        }
        dfs(node->left, freq, fnl);
        dfs(node->right, freq, fnl);
        freq[node->val]--;  
        if (freq[node->val] == 0) {
            freq.erase(node->val);
        }
    }

public:
    int pseudoPalindromicPaths(TreeNode* root) {
        ios::sync_with_stdio(false); 
        cin.tie(0); cout.tie(0);
        int fnl = 0;
        unordered_map<int, int> freq;
        dfs(root, freq, fnl);
        return fnl;
    }
};