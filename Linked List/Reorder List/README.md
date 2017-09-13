## Reorder List「LeetCode 143」

题目：给定一个链表，把最后一个结点插入到第1个结点后，倒数第二个结点插入到第2个结点后，倒数第三个结点插入到第3个结点后，以此类推……

```
Given a singly linked list L: L0->L1->…->Ln-1->Ln,
reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
```

解题思路：

1. 利用快慢指针法，找出链表中间点，分成两部分
2. 把后半部分的链表进行翻转操作
3. 把翻转后的后半部分链表一个个插入到前半部分
