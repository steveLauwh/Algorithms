## Moving Average from Data Stream「346」

题目：从数据流中移动平均值，给定一个滑动窗口值，计算在滑动窗口下，求所有值的平均值。

```
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
```

解题思路：

1. 给定一个固定值，每次读入一个数字，如果加上这个数字后总个数大于限制的个数，那么我们移除最早进入的数字，然后返回更新后的平均数
2. 使用 queue 来存储，当队列中元素个数大于限定个数，就移除队列首元素，并且 sum 要减去移除元素，如果没有大于限定个数，就累加 sum
