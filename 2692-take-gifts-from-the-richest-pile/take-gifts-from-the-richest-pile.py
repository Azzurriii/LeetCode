import heapq
import math

class Solution:
    def pickGifts(self, gifts: list[int], k: int) -> int:
        """
        Calculates the number of gifts remaining after k seconds.

        Args:
            gifts: A list of integers representing the number of gifts in each pile.
            k: The number of seconds to perform the operations.

        Returns:
            The total number of gifts remaining after k seconds.
        """
        
        heap = [-gift for gift in gifts] # Use negative values for max heap
        heapq.heapify(heap)

        for _ in range(k):
            max_gifts = -heapq.heappop(heap)
            
            remaining_gifts = math.floor(math.sqrt(max_gifts))
            heapq.heappush(heap, -remaining_gifts)

        return -sum(heap)