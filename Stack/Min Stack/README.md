## 最小栈 Min Stack「LeetCode 155」

题目：
```
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
```
保证时间复杂度都是 O(1)。

题解：

栈是一种先入后出的数据结构。

最小栈比原有的栈 stack 多了一个功能，获取栈的最小值。

**创建一个辅助栈 B，辅助栈 B 的栈顶元素始终是原有栈 A 的最小值。**

当第一个元素进入原有栈 A，也让新元素也进入辅助栈 B。这个唯一的元素就是原有栈 A 的当前最小值。

入栈 push：每当有新元素 x 进入原有栈 A，将新元素 x 与辅助栈 B 的栈顶元素比较，如果小，则就可以入辅助栈 B，否则就不入辅助栈 B。

出栈 pop：每当原有栈 A 有元素出栈，如果出栈元素是原有栈 A 当前最小值，那么让辅助栈 B 的栈顶元素也出栈。

获取栈顶元素 top：获取原有栈 A 的栈顶元素。

获取栈的最小值 getMin：获取辅助栈 B 的栈顶元素。

