## 最小生成树 Minimum Span Tree

在一给定的无向图 G = (V, E) 中，w(u, v) 代表连接顶点 u 与顶点 v 的边，而 w(u, v) 代表此边的权重，若存在 T 为 E 的子集且为无循环图，使得
的 w(T) 最小，则此 T 为 G 的最小生成树。
 
最小生成树其实是最小权重生成树的简称。

如果无向连通图中，边的权值有相等情况(如果横切边有相等的边)，那么最小生成树不只有一条。

### [有权图](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Graph/Minimum%20Span%20Tree/Weighted%20Graph)

图可以用邻接矩阵(稠密图)和邻接表(稀疏图)来表示，对于一个有权图，由于有边的权值，所以需要在邻接矩阵和邻接表中加入边的权值。

邻接矩阵，其实是一个二维数组结构，w(u, v) 代表连接顶点 u 与顶点 v 的边，w(u, v) 代表此边的权重，二维数组表示就是 `arr[u][v] = w(u, v)`。

邻接表，是每个顶点，将其相邻的顶点和两点之间的权值，存放到向量或链表中。

用一个类来单独表示顶点之间的权值。

### Prim 算法——贪心算法

* [利用最小堆实现 Prim 算法](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Graph/Minimum%20Span%20Tree/Prim/LazyPrimMST)

原理：根据切分定理，任意选取图中的一个顶点，把该顶点的所有横切边，入最小堆，取出最小权值(该边一定为最小生成树的边)，该边的另一个顶点没有访问过，现在对两个顶点进行切分，它们的所有横切边，入最小堆，取出最小权值，如果该最小权值边的另一个顶点没有被访问过，就加入切分阵营，继续加入横切边到最小堆中，反复操作，直到所有顶点都被访问过，找出最小生成树。

时间复杂度为 O(ElogE)。

**缺点：图中的每个边都会进入最小堆中，并且进入的横切边不一定是最小生成树的边。**
  
* [利用最小索引堆实现 Prim 算法](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Graph/Minimum%20Span%20Tree/Prim/PrimMST)
 
时间复杂度为 O(ElogV)。

每个顶点对应索引，每个顶点总是保存最小的权值。

### [Kruskal 算法](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Graph/Minimum%20Span%20Tree/Kruskal)

最小堆 + 并查集 实现 Kruskal 算法。

原理：对图中的所有边的权值进行`排序`，依次取最小的边，并且利用`并查集`来判断环。

利用 Union Find 来判断是否构成环。

时间复杂度为 O(ElogE)。
