# DP: dp[i][j] = max(num[i] * num[k] * num[j] + dp[i][k] + dp[k][j])

from typing import List


class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        nums_len = len(nums)
        dp = [[0] * nums_len for _ in range(nums_len)]

        # for i in reversed(range(nums_len - 2)):
        for i in range(nums_len - 3, -1, -1):
            for j in range(i + 2, nums_len):
                for k in range(i+1, j):
                    dp[i][j] = max(
                        dp[i][j], 
                        nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j]
                    )
        return dp[0][nums_len-1]
