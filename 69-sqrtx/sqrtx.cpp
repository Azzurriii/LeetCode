class Solution {
private:
    int sqrtHelper(int x, int left, int right) {
        if (left > right) {
            return right;
        }
        
        int mid = left + (right - left) / 2;

        if (mid <= x / mid) {
            // If mid is less than or equal to the square root of x, search in the right half.
            return sqrtHelper(x, mid + 1, right);
        } else {
            // If mid is greater than the square root of x, search in the left half.
            return sqrtHelper(x, left, mid - 1);
        }
    }

public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        return sqrtHelper(x, 1, x);
    }
};
