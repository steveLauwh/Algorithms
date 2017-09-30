## 最短路径算法 Shortest-path Algorithms

最小生成树，对于无向图来说；

最短路径问题，一般对于有向图，同时也适用无向图。

松弛操作(Relaxation)是求解最短路径算法的核心。

### [Dijkstra 算法](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Graph/Shortest-path%20Algorithms/Dijkstra)

贪婪算法

Dijkstra 算法适用于处理没有负权边的图。

时间复杂度为 O(ElogV)。

借助最小索引堆来实现。

### [Bellman Ford 算法](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Graph/Shortest-path%20Algorithms/Bellman%20Ford)

Bellman Ford 算法可以处理有负权边的图，但是图中不能有负权环。

复杂度为 O(EV)。

> **Bellman Ford 算法可以判断图中是否有负权环**

如果一个图没有负权环，从一点到另外一点的最短路径，最多经过所有的 V 个顶点，有 V-1 条边；否则，存在顶点经过了两次，既存在负权环。

> **Bellman Ford 算法原理**

对所有的点进行第 1 次松弛操作，找到从原点开始，经过 1 条边的最短路径；

对所有的点进行第 2 次松弛操作，找到从原点开始，经过 2 条边的最短路径；

对一个点的一次松弛操作，就是找到经过这个点的另外一条路径，多一条边，权值更小。

如果一个图没有负权环，从一点到另外一点的最短路径，最多经过所有的 V 个顶点，有 V-1 条边，对所有的点进行 V-1 次松弛操作。

对所有的点进行 V-1 次松弛操作，理论上就找到了从源点到其他所有点的最短路径。

如果还可以继续松弛，所说原图中有负权环。

## 单源最短路径算法

|   算法      |    |   |时间复杂度|
| --------   | -----:  | :----:  |
| Dijkstra     | 无负权边   |   有向无向图均可    |O(ElogV)|
| BellmanFord  | 无负权环   |   有向图   |O(VE)|
| 拓扑排序      | 有向无环图 DAG|  有向图  |O(V+E)|

## 延伸

> **所有对最短路径算法**

Floyed 算法，处理无负权环的图 O(V^3)。

> **最长路径算法**

最长路径问题不能有正权环。

无权图的最长路径问题是指数级难度的。

对于有权图，不能使用 Dijkstra 求最长路径问题。

可以使用 Bellman-Ford 算法。
