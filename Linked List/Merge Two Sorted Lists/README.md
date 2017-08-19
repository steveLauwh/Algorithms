## Merge Two Sorted Lists 合并两个已排序的链表「LeetCode 21」

**题目要求**

```
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
    }
};
```

将两个已排序的链表合并成一个新的链表。合并后的链表肯定也是排好序的。

思路：

* 为了更好操作合并的新链表，首先生成哑节点 dummy(-1)；
* 以某一个链表为主链表，以它为准，dummy(-1) 的 next 指向它，另外新增遍历指针 p 指向 dummy，p 是在 l1 和 l2 两个链表中来回移动；
* 涉及到链表节点的值比较大小，插入操作，插入一般往前插入；
* 假设 l1 链表为主链表，要把 l2 合并到 l1 上，当 l1->val > l2->val，那么就把 l2 指向的节点插入到 l1 上；否则 l1 指向它的下一个节点；
* l1 作为主链表，当 l1 遍历完，但是 l2 没有遍历完；需要把 l2 剩下合并到 l1 上；当 l2 遍历完，l1 没有遍历完，因为主链表，所以不需要操作。

总结：

* 链表的操作，注意先后顺序，不要出现断链；
* 要思考判断条件是什么，边界情况如何。
