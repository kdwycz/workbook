class Solution:
    def twoSum(self, nums, target):
        snums = sorted(nums)
        l = 0
        r = len(nums) - 1
        while l < r:
            if snums[l] + snums[r] > target:
                r -= 1
            elif snums[l] + snums[r] < target:
                l += 1
            else:
                break
        else:
            return
        k1 = nums.index(snums[l]) + 1
        if snums[l] == snums[r]:
            k2 = nums[k1:].index(snums[r]) + k1 + 1
        else:
            k2 = nums.index(snums[r]) + 1
        return (min(k1,k2),max(k1,k2))


a = [0, 2, 3, 0]
b = 0
s = Solution()
print(s.twoSum(a, b))
