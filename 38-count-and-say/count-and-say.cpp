class Solution {
public:
    string countAndSay(int n) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        if (n == 1)
        return "1";
        
        string s = countAndSay(n - 1);
        string ans = "";
        int count = 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == s[i + 1])
            {
                count++;
            }
            else
            {
                ans += to_string(count) + s[i];
                count = 1;
            }
        }
        return ans;

    }
};