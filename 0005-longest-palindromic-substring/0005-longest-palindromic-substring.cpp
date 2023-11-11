class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0, maxLen = 0;

        for (int i = 0; i < n; i++) {
            // Expand around center for odd length palindrome
            int len1 = expandAroundCenter(s, i, i);
            // Expand around center for even length palindrome
            int len2 = expandAroundCenter(s, i, i + 1);

            // Find the maximum length palindrome centered at i
            int len = max(len1, len2);

            // Update start index and max length if a longer palindrome is found
            if (len > maxLen) {
                start = i - (len - 1) / 2;
                maxLen = len;
            }
        }

        return s.substr(start, maxLen);
    }

private:
    int expandAroundCenter(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the length of the palindrome centered at left and right
        return right - left - 1;
    }
};
