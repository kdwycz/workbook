class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        queue = [0] * len(nums)
        answer = []
        head = tail = 0
        for i in range(len(nums)):
            while (head < tail and nums[i] >= nums[queue[tail - 1]]):
                tail -= 1
            queue[tail] = i

            if (tail >= 0 and queue[tail] - queue[head] >= k):
                head += queue[tail] + 1 - k - queue[head];
            if i >= k - 1:
                answer.append(nums[queue[head]])
            tail += 1

        return answer