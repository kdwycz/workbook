# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        carry = 0
        lsum = ListNode(0)
        lnode = lsum
        i1 = l1
        i2 = l2
        while i1 or i2:
            lnode.next = ListNode(carry)
            lnode = lnode.next
            if i1:
                lnode.val += i1.val
                i1 = i1.next
            if i2:
                lnode.val += i2.val
                i2 = i2.next
            carry = lnode.val // 10
            lnode.val %= 10
        if carry:
            lnode.next = ListNode(carry)
        return lsum.next

# test
s = Solution()
