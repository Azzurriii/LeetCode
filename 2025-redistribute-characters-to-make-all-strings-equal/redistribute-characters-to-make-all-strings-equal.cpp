class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        unordered_map<char, int> count;
        for (int i = 0; i < n; i++) {
            for (char c : words[i]) {
                count[c]++;
            }
        }
        for (auto it = count.begin(); it != count.end(); it++) {
            if (it->second % n != 0) {
                return false;
            }
        }
        return true;
    }
};