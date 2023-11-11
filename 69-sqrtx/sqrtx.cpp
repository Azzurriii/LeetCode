class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        int low = 0;
        int high = x;
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (x / mid == mid) return mid;
            else if (x / mid > mid) {
                if (x / (mid + 1) < mid + 1) return mid;
                else low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return mid;
    }
};