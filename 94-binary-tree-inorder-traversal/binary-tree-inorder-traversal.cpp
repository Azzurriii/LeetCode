//#Recursion
// class Solution {
// private:
//     void LNR(TreeNode* root, vector<int>& res)
//     {
//         if(root){
//             LNR(root->left, res);
//             res.push_back(root->val);
//             LNR(root->right, res);
//         }
//     }
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         LNR(root, res);
//         return res;
//     }
// };

//#Daily 9/12: No Recursion, Iterative.
class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            
            curr = st.top();
            st.pop();
            result.push_back(curr->val);
            
            curr = curr->right;
        }
        
        return result;
    }
};