class Solution {
public:
    int minOperations(string s) {
        int n = s.size(), op[2] = {0};
        for(int i = 0; i < n; i += 2)
            op[s[i] == '0']++;
            
        for (int i = 1; i<n; i+=2)
            op[s[i] == '1']++;
        return min(op[0], op[1]);
    }
};