class Solution {
public:
    bool isPowerOfTwo(int n) {
        int i = 0;
        if(n==1) return true;
        while(pow(2, i) < n){
            if(pow(2, i+1)==n) return true;
            i++;
        }
        return false;
    }
};