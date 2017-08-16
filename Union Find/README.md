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

### Quick Find

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
        
        // O(n), 遍历, 当 将所有等于 arr[p]，赋值等于 arr[q]
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

