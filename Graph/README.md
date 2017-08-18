# Graph

图论能解决计算机科学很多问题。

图的分类：无向图和有向图。其中无向图是一种特殊的有向图。

根据边有没有权值，分为无权图和有权图。

## 图的表示

* 邻接矩阵(二维)：适合表示稠密图
* 邻接表：适合表示稀疏图

**[邻接矩阵的数据结构表示](https://github.com/steveLauwh/Data-Structures-And-Algorithms/blob/master/Graph/DenseGraph/DenseGraph.h)**
```cpp
int n;
int m;
bool directed;
vector<vector<bool>> g; // 邻接矩阵的值用 0 和 1 表示
```

**[邻接表的数据结构表示](https://github.com/steveLauwh/Data-Structures-And-Algorithms/blob/master/Graph/SparseGraph/SparseGraph.h)**
```cpp
int n;  // 图的顶点
int m;  // 图的边
bool directed; // 方向
vector<vector<int>> g;  // 邻接表的特点，还可以用链表表示
```

