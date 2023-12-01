class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
       string concatWord1;
        for (const string& str : word1) {
            concatWord1 += str;
        }

        string concatWord2;
        for (const string& str : word2) {
            concatWord2 += str;
        }

        return strcmp(concatWord1.c_str(), concatWord2.c_str()) == 0;
    }
};