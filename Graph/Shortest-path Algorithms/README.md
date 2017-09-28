## 最短路径算法 Shortest-path Algorithms

最小生成树，对于无向图来说；但是最短路径问题，一般对于有向图，同时也适用无向图。

松弛操作是求解最短路径算法的核心。

### [Dijkstra 算法](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Graph/Shortest-path%20Algorithms/Dijkstra)

贪婪算法

Dijkstra 算法适用于处理没有负权边的图。

时间复杂度为 O(ElogV)。

借助最小索引堆来实现。

### [Bellman Ford 算法](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Graph/Shortest-path%20Algorithms/Bellman%20Ford)

Bellman Ford 算法可以处理有负权边的图，但是图中不能有负权环。

复杂度为 O(EV)。

> **Bellman Ford 算法可以判断图中是否有负权环**

如果一个图没有负权环，从一点到另外一点的最短路径，最多经过所有的V个顶点，有V-1条边；否则，存在顶点经过了两次，既存在负权环。

> **Bellman Ford 算法原理**



