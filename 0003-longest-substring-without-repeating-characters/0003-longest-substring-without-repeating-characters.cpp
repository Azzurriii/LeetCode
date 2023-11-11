class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st; // Initialize an unordered set to store unique characters.
        int n = s.size(); // Get the length of the input string.
        int len = 0; // Initialize the length of the longest substring.
        int l = 0; // Initialize the left pointer.

        for (int r = 0; r < n; r++) {
            if (st.count(s[r]) == 0) { // If the character at index 'r' is not in the set:
                st.insert(s[r]); // Insert it into the set to keep track of unique characters.
                len = max(len, r - l + 1); // Update the length of the longest substring.
            } else { // If the character at index 'r' is already in the set (repeated character):
                while (st.count(s[r])) { // While the character at 'r' is still in the set:
                    st.erase(s[l]); // Erase the character at 'l' from the set.
                    l++; // Move the left pointer to the right.
                }
                st.insert(s[r]); // Insert the current character 's[r]' into the set.
            }
        }
        return len; // Return the length of the longest substring without repeating characters.
    }
};