class Solution:
    def smallestRangeI(self, A: List[int], K: int) -> int:
        b_max = max(A) - K
        b_min = min(A) + K
        return 0 if b_max - b_min < 0 else b_max - b_min
