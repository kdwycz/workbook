class MinStack:

    def __init__(self):
        self.stack = []
        self.min = []
        

    def push(self, x: int) -> None:
        self.stack.append(x)
        if not self.min:
            min = x
        else:
            min = x if x < self.min[-1] else self.min[-1]
        self.min.append(min)

    def pop(self) -> None:
        if not self.stack:
            return
        self.min.pop()
        self.stack.pop()
        

    def top(self) -> int:
        return self.stack[-1] if self.stack else None
        

    def getMin(self) -> int:
        return self.min[-1] if self.min else None
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()