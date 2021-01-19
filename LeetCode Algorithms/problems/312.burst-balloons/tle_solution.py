# 状态：超出时间限制
# 最后执行的输入：[8,2,6,8,9,8,1,4,1,5,3,0,7,7,0,4,2,2,5,5]

from copy import copy

class Solution:
    solu_dict = None

    def maxCoins(self, nums: List[int]) -> int:
        if self.solu_dict is None:
            self.solu_dict = {}

        if len(nums) == 1:
            return nums[0]

        # 记忆化搜索，查找结果
        str_nums = str(nums)
        if str_nums in self.solu_dict:
            return self.solu_dict[str_nums]

        result = 0
        for i, val in enumerate(nums):
            new_nums = copy(nums)
            new_nums.pop(i)
            news_result = self._burst_balloons(i, nums) + self.maxCoins(new_nums)
            result = max(result, news_result)

        # 保存记忆化搜索的结果并返回
        self.solu_dict[str_nums] = result
        return result

    def _burst_balloons(self, index: int, nums: List[int]) -> int:
        nums_len = len(nums)
        if not nums or index < 0 or index >= nums_len:
            return 1
        elif len(nums) <= 1:
            return nums[0]
        elif index == 0:
            return nums[index] * nums[index + 1]
        elif index == nums_len - 1:
            return nums[index - 1] * nums[index]
        else:
            return nums[index - 1] * nums[index] * nums[index + 1]
