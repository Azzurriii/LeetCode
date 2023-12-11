class Solution{
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int targetFrequency = n >> 2;

        for (int i = 0; i < n; i += targetFrequency) {

            auto lower = lower_bound(arr.begin(), arr.end(), arr[i]);
            auto upper = upper_bound(arr.begin(), arr.end(), arr[i]);
            int frequency = upper - lower;
            if (frequency > targetFrequency) {
                return arr[i];
            }
        }

        return 0;
    }
};