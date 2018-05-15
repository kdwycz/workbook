class Solution:
    def twoSum(self, nums, target):
        nums_dict = dict()
        for k, v in enumerate(nums):
            if target - v in nums_dict:
                return (nums_dict[target - v], k)
            nums_dict[v] = k


nums = [2, 7, 11, 15]
target = 9
solution = Solution()
print(solution.twoSum(nums, target))
