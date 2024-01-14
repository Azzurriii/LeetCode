class Solution {
public:
    bool closeStrings(string word1, string word2){
        int n = word1.length();
        int m = word2.length();
        if(n != m){
            return false;
        }
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        for(int i = 0; i < n; i++){
            count1[word1[i] - 'a']++;
            count2[word2[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if((count1[i] == 0 && count2[i] != 0) || (count1[i] != 0 && count2[i] == 0)){
                return false;
            }
        }
        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());
        return count1 == count2;

    }
};