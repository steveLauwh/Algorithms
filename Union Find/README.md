## 并查集 「Union Find」

并查集：是一种树形结构，用于处理连接问题。

> 连接问题

* 网络中节点间的连接状态
* 数学中的集合类实现

> 并查集的两个操作

* 并：`union(p, q)`
* 查：`find(p)`

用上面两个操作来解决连接问题：`isConnected(p, q)`

并查集的基本数据可以用 **数组** 表示。

### [Quick Find](https://github.com/steveLauwh/Data-Structures-And-Algorithms/blob/master/Union%20Find/QuickFind.cpp)

Quick Find 下 find 的时间复杂度为 O(1)。

Quick Find 下 union 的时间复杂度为 O(n)。

查找操作很高效，但是合并操作需要遍历一次数组。

```cpp
class UnionFind {
private:
    int *arr;  // 本身就是一个数组
    int count;
    
public:
    UnionFind(int n)
    {
        arr = new int[n];
        
        for (int i = 0; i < n; i++)
        {
            arr[i] = i;
        }
        
        count = n;
    }
    
    ~UnionFind()
    {
        delete[] arr;
    }
    
    // 查找操作
    int find(int i)
    {
        assert(i >= 0 && i < count);
        return arr[i];
    }
    
    // 查看元素 p 和 元素 q 是否连接, 当 arr[p] == arr[q], 表示连接
    bool isConnected(int p, int q)
    {
        return find(p) == find(q);
    }
    
    // 合并元素 p 和 元素 q
    void unions(int p, int q)
    {
        int pID = find(p);
        int qID = find(q);
        
        if (pID == qID)
            return;
        
        // O(n), 遍历, 当将所有等于 arr[p]，赋值等于 arr[q]
        for (int i = 0; i < count; i++)
        {
            if (arr[i] == pID)
            {
                arr[i] = qID;
            }
        }       
    }    
};
```

### [Quick Union](https://github.com/liuyubobobo/Play-with-Algorithms/blob/master/06-Union-Find/Course%20Code%20(C%2B%2B)/03-Quick-Union/UnionFind2.h)

Quick Union 改进的地方：并查集每个元素看作一个节点，现在把每个节点的父亲节点组成数组。

Quick Union 下 union 的时间复杂度为 O(h), h 为树的高度。

```cpp
class UnionFind
{
private:
    int *parent;  // 使用一个数组构建一棵指向父节点的树
    int count;
    
public:
    UnionFind(int n)
    {
        parent = new int[n];
        count = n;
        
        for (int i = 0; i < count; i++)
        {
            parent[i] = i;  // 每一个 parent[i] 指向自己，表示根节点
        }
    }
    
    ~UnionFind()
    {
        delete[] parent;
    }
    
    // 查找过程，根节点的特点: parent[p] == p
    int find(int p)
    {
        assert(p >= 0 && p < count);
        
        // 不断去查找自己的父亲节点, 直到到达根节点
        while (p != parent[p])
        {
            p = parent[p];
        }
        
        return p;  // 最终根节点
    }
    
    // 查看元素 p 和 元素 q 是否连接, 当 arr[p] == arr[q], 表示连接
    bool isConnected(int p, int q)
    {
        return find(p) == find(q);
    }
    
    // 合并元素 p 和 元素 q
    void unions(int p, int q)
    {
        int pID = find(p);  // p 的根节点
        int qID = find(q);  // q 的根节点
        
        if (pID == qID)
        {
            return;
        }
        
        parent[pID] = qID;
    }  
};
```

### 基于 size 优化的 Union Find

在 Quick Union 里的合并操作 unions，分别找到两个元素的根，以一个根节点指向另一个根节点的父亲节点(自己)，这里并没有考虑这两个元素的根节点包含子节点的个数，应该包含子节点的个数少的根节点的父亲节点指向大的一侧。


