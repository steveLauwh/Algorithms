## Remove Duplicates from Sorted List「LeetCode 83」

题目：从已排序的链表中，删除所有重复的元素，每个节点元素只能出现一次。

```
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
```
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
    }
};
```

解题思路：

**先确定前条件/不变式/终止条件/边界条件，然后写出正确的代码。**

递归和迭代两个版本。

**递归版：**

1. 确定递归终止条件: 当前访问节点为空；
2. 返回链表，所以借助哑节点 dummy；
3. 写一个递归函数，两个形参，前一个节点和当前节点；如果前一个节点与当前节点，比较，值相等，就删除当前节点，将前一个节点和下一个节点入参，继续递归；
   否则不等，将前一个节点的 next 节点 和 当前节点的 next 节点入参，继续递归。
   
**迭代版：**

一个 for 循环搞定。

1. 终止条件，也是当前访问节点为空；
2. 循环条件，当前节点为前一个节点的 next；
3. 如果前一个节点与当前节点的值相等，就删掉当前节点，否则前一个节点指向当前节点。

## Remove Duplicates from Sorted List II「LeetCode 82」

题目：只要元素重复，就把所有重复的元素删除。

```
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
```

解题思路：

**递归版：**

1. 如果前一个节点与当前节点的值相等，此时循环,看是否连续的节点是否相等，如果相等，删除节点，最后删除重复的最后一个元素，继续递归
2. 否则递归
3. 注意返回值

**迭代版：**

1. 借用哑节点 dummy
2. 终止条件：当前节点不为空
3. 当有重复节点，需要借用一个 bool 变量，如果 bool 变量为 true，那么需要删除重复的最后一个元素。
