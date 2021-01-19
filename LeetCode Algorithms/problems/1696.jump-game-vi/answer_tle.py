# 57 / 65 个通过测试用例 状态：超出时间限制
# 最后执行的输入：太长不写了……

class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        # from copy import copy
        # dp = copy(nums)
        dp = nums
        for i in range(1, len(nums)):
            dp[i] += max(dp[max(i - k, 0): i])
        return dp[len(nums) - 1]