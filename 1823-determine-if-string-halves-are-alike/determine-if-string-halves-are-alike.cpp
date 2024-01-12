class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        size_t midpoint = s.length() / 2;

        string a = s.substr(0, midpoint);
        string b = s.substr(midpoint);
        int count1 = 0;
        int count2 = 0;
        for(auto c: a){
            count1 += vowels.count(c);
        }
        for(auto c: b){
            count2 += vowels.count(c);
        }
        return count1 == count2;
    }
};