class Solution {
private:
    void helper(int open, int close, int n, string& s, vector<string>& ans){
        if (open == n && close == n) {
            ans.push_back(s);
            return;
        }
        if (open < n) {
            s.push_back('(');
            helper(open + 1, close, n, s, ans);
            s.pop_back();
        }
        if (close < open) {
            s.push_back(')');
            helper(open, close + 1, n, s, ans);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        int open = 0;
        int close = 0;
        helper(open, close, n, s, ans);
        return ans;
    }
};