## Delete Node in a Linked List「LeetCode 237」

题目要求是在单链表中删除一个节点，已经告诉要删除的节点，怎么去删除。

```cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    void deleteNode(ListNode *node) {
    
    }
};
```

**如何删除指定的节点？**

方法：跳出传统思维(用删除的前一个节点来操作)，单链表的特点是不知道前驱节点。既然已知删除节点，那么很容易知道它的下一个节点，将下一个节点的值赋给待删除节点，这样删除节点和它的下一个节点就是一样，用删除节点的 next 指向它的next的next；这样只用删除待删除节点的下一个节点就可以了。

```cpp
void deleteNode(ListNode *node) {
    
    ListNode *nextNode = node->next;
    
    node->val = nextNode->val;
    node->next = nextNode->next;
    
    delete nextNode;
}
```

