# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def serialization(self, listnode):
        num_str = ''
        while listnode:
            num_str = str(listnode.val) + num_str
            listnode = listnode.next
        return int(num_str) if num_str else 0
    
    def deserialization(self, number):
        num_str = str(number)
        listnode = None
        for str_ in num_str:
            next_node = listnode
            listnode = ListNode(x=str_)
            listnode.next = next_node
        return listnode
    
    def addTwoNumbers(self, l1, l2):
        return self.deserialization(self.serialization(l1) + self.serialization(l2))


# l1 = [2, 4, 3]
# l2 = [5, 6, 4]

# solution = Solution()
# print(solution.addTwoNumbers(l1, l2))
