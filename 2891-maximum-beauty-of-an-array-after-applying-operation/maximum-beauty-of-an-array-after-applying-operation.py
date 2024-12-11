class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        
        nums.sort()
        
        ans = 0

        for i in range(len(nums)):
            left = bisect_left(nums, nums[i] - 2*k)
            ans = max(ans, i - left + 1)
        return ans