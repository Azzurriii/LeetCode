class Solution{
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int targetFrequency = n >> 2;

        for (int i = 0; i < n; i += targetFrequency) {
            int currentElement = arr[i];

            auto lower = lower_bound(arr.begin(), arr.end(), currentElement);
            auto upper = upper_bound(arr.begin(), arr.end(), currentElement);

            int frequency = upper - lower;

            if (frequency > targetFrequency) {
                return currentElement;
            }
        }

        return 0;
    }
};