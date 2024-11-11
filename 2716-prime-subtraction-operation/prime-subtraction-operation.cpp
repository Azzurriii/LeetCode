class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    bool primeSubOperation(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());

        // Precompute previous primes
        vector<int> prevPrime(maxElement + 1, 0);
        for (int i = 2; i <= maxElement; i++) {
            if (isPrime(i)) {
                prevPrime[i] = i;
            } else {
                prevPrime[i] = prevPrime[i - 1];
            }
        }

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int bound = (i == 0) ? nums[i] : nums[i] - nums[i - 1];
            if (bound <= 0) {
                return false;
            }

            int largestPrime = prevPrime[bound - 1];
            nums[i] -= largestPrime;
        }

        return true;
    }
};
