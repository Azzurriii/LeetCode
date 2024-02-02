class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string digits = "123456789";
        int n = digits.length();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int num = stoi(digits.substr(i, j - i + 1));
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};