// class Solution {
// public:
//     //Sliding windows
//     int findSpecialInteger(vector<int>& arr) {
//         // int windowSize = arr.size() / 4;

//         // for (int i = 0; i < arr.size() - windowSize; i++) {
//         //     if (arr[i] == arr[i + windowSize]) {
//         //         return arr[i];
//         //     }
//         // }
        
//         // return 0;
//         int l = arr.size();
//         int p = l >> 2;
//         for (int i = 0; i < l; i += p) {
//             if (upper_bound(arr.begin(), arr.end(), arr[i]) - lower_bound(arr.begin(), arr.end(), arr[i]) > l >> 2) {
//                 return arr[i];
//             }
//         }
//         return 0;
//     }
// };
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int count = 1;
        int p = arr[0];
        int rate = n / 4;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == p) count++;
            else count = 1;

            if (count > rate) return p;
            p = arr[i];
        }
        return count;
    }
};