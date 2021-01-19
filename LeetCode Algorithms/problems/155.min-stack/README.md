Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

 - push(x) -- Push element x onto stack.
 - pop() -- Removes the element on top of the stack.
 - top() -- Get the top element.
 - getMin() -- Retrieve the minimum element in the stack.

Example:

```
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
```

维护一个 stack 数组和一个 min 数组， min 数组的第 n 个元素值为 stack 数组前 n 个元素的最小值