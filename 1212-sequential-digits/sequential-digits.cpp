class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> q;
        for (int i = 1; i <= 9; i++) {
            q.push(i);
        }

        while (!q.empty()) {
            int num = q.front();
            q.pop();

            if (num >= low && num <= high) {
                ans.push_back(num);
            }

            int lastDigit = num % 10;

            if (lastDigit < 9) {
                q.push(num * 10 + lastDigit + 1);
            }
        }

        return ans;
    }
};