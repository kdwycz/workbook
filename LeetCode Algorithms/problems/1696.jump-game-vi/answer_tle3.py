# 60 / 65 个通过测试用例 状态：超出时间限制
# 最后执行的输入：太长不写了……

class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:

        class SegmentTree:
            INIT_NUM = -10 ** 9
            tree = None
            length = 0

            def __init__(self, length):
                self.length = length
                self.tree = [self.INIT_NUM] * ((length + 1) * 4)
            
            def update(self, index, num):
                self._update(index, num, 1, self.length, 1)
            
            def query(self, left, right):
                return self._query(left, right, 1, self.length, 1)

            def _update(self, index, num, left, right, root):
                if left == right:
                    if index == left:
                        self.tree[root] = num
                    return
                mid = (left + right) // 2
                if index <= mid:
                    self._update(index, num, left, mid, root * 2)
                else:
                    self._update(index, num, mid + 1, right, root * 2 + 1)
                self.tree[root] = self._get_value(
                    self.tree[root * 2],
                    self.tree[root * 2 + 1]
                )

            def _query(self, left, right, q_left, q_right, root):
                if right < q_left or left > q_right:
                    return self.INIT_NUM
                if left <= q_left and right >= q_right:
                    return self.tree[root] 
                mid = (q_left + q_right) // 2
                return self._get_value(
                    self._query(left, right, q_left, mid, root * 2),
                    self._query(left, right, mid + 1, q_right, root * 2 + 1)
                )

            def _get_value(self, a, b):
                return max(a, b)

        dp = nums
        tree = SegmentTree(length=len(nums))
        tree.update(index=1, num=nums[0])
        for i in range(1, len(nums)):
            dp[i] += tree.query(left=max(i-k, 0)+1, right=i+1)
            tree.update(index=i+1, num=dp[i])
        return dp[len(nums) - 1]