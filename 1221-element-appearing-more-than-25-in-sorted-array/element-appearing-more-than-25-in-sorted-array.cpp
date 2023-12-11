class Solution {
public:
    //Sliding windows
    int findSpecialInteger(vector<int>& arr) {
        int windowSize = arr.size() / 4;

        for (int i = 0; i < arr.size() - windowSize; i++) {
            if (arr[i] == arr[i + windowSize]) {
                return arr[i];
            }
        }
        
        return 0;
    }
};