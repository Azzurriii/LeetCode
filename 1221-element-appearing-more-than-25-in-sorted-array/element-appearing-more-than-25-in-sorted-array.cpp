class Solution {
public:
    //Sliding windows
    int findSpecialInteger(vector<int>& arr) {
        // int windowSize = arr.size() / 4;

        // for (int i = 0; i < arr.size() - windowSize; i++) {
        //     if (arr[i] == arr[i + windowSize]) {
        //         return arr[i];
        //     }
        // }
        
        // return 0;
        int l = arr.size();
        int p = l / 4 + (l % 4 != 0);
        for (int i = 0; i < l; i += p) {
            int res = upper_bound(arr.begin(), arr.end(), arr[i]) - lower_bound(arr.begin(), arr.end(), arr[i]);
            if (res > l / 4) {
                return arr[i];
            }
        }
        return 0;
    }
};