class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> cnt(26, 0);
        vector<int> cnt2(26, 0);
        for(char& ch : chars)
            ++cnt[ch - 'a'];
        int result = 0;
        bool isGood;
        for(string& word : words) {
            isGood = true;
            fill(cnt2.begin(), cnt2.end(), 0);
            for(char& ch : word)
                ++cnt2[ch - 'a'];
            for(char& ch : word) {
                if(cnt2[ch - 'a'] > cnt[ch - 'a']) {
                    isGood = false;
                    break;
                }
            }
            if(isGood) {
                result += word.size();
            }
        }      
        return result;
    }
};
auto speedup = cin.tie(NULL) -> sync_with_stdio(false);