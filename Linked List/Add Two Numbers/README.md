## Add Two Numbers 链表相加「LeetCode 2」

题目要求

You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

342 + 465 = 807， 个位是链表第一个节点。

给定两个非空链表(单链表)，表示两个非负整数，链表的每个节点都是用一位数字表示(0~9)，这些数字倒序存储在链表上，两个链表相加，返回一个相加和的链表。

解决思路：



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    
};
