class Solution:
    def maxCount(self, banned: list[int], n: int, maxSum: int) -> int:
        # Sort the banned list
        banned.sort()

        banned_idx = 0
        count = 0

        # Check each number from 1 to n while the sum is valid
        for num in range(1, n + 1):
            # Skip if the current number is in the banned list
            if banned_idx < len(banned) and banned[banned_idx] == num:
                # Handle duplicate banned numbers
                while banned_idx < len(banned) and banned[banned_idx] == num:
                    banned_idx += 1
            else:
                # Include the current number if possible
                maxSum -= num
                if maxSum >= 0:
                    count += 1
                else:
                    break

        return count