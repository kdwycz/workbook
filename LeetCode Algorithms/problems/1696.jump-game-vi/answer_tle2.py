# 64 / 65 个通过测试用例 状态：超出时间限制
# 最后执行的输入：太长不写了……数组里几乎全是-1

class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        # 相对上一个做了简单优化，dp[i] 可以由 dp[j] for j in range(i-1,i-k,-1) 跳过来，如果num[j]是正数，那能跳到i的最佳方案必然要通过j。
        # 所以被全-1数组制裁了……
        dp = [0] * len(nums)
        dp[0] = nums[0]
        for i in range(1, len(nums)):
            max_num = -10**9
            for j in range(i - 1, max(i - k - 1, -1), -1):
                max_num = max(max_num, dp[j])
                if nums[j] >= 0:
                    break 
            dp[i] += nums[i] + max_num
        return dp[len(nums) - 1]
