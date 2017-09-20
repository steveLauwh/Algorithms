# ifndef __LAZYPRIMMST_H_
# define __LAZYPRIMMST_H_

#include <iostream>
#include <vector>
#include <cassert>
#include "WeightedGraphEdge.h"
#include "MinHeap.h"

using namespace std;

// Prim 算法求图的最小生成树 (利用最小堆数据结构)
template <typename Graph, typename Weight>
class LazyPrimMST {
public:
    // 构造函数
    LazyPrimMST(Graph &graph) : G(graph), pq(MinHeap<WeightedGraphEdge<Weight>>(graph.E())) {
        // 初始化
        marked = new bool[G.V()];
        
        for (int i = 0; i < G.V(); i++) {
            marked[i] = false;
        }
        
        mst.clear();
        
        // Lazy Prim
        visit(0);
        
        while (!pq.isEmpty()) {
            // 使用最小堆找出已经访问的边中权值最小的边
            WeightedGraphEdge<Weight> e = pq.extractMin();
            
            // 如果这条边的两端都已经访问过了, 则扔掉这条边
            if (marked[e.V()] == marked[e.W()]) {
                continue;
            }
            
            // 否则, 这条边则应该存在在最小生成树中
            mst.push_back(e);
            
            // 访问和这条边连接的还没有被访问过的节点
            if (!marked[e.V()]) {
                visit(e.V());
            } else {
                visit(e.W());
            }
        }
        
        // 计算最小生成树的权值
        mstWeight = mst[0].wt();
        
        for (int i = 1; i < mst.size(); i++) {
            mstWeight += mst[i].wt();
        }
    }
    
    ~LazyPrimMST() {
        delete[] marked;
    }
    
    // 返回最小生成树的所有边
    vector<WeightedGraphEdge<Weight>> mstEdges() {
        return mst;
    }
    
    // 返回最小生成树的权值
    Weight result() {
        return mstWeight;
    }

private:
    Graph &G;  // 图的引用
    MinHeap<WeightedGraphEdge<Weight>> pq;  // 最小堆
    bool *marked;  // 标记数组，标记节点是否被访问过
    vector<WeightedGraphEdge<Weight>> mst;  // 最小生成树所包含的所有边
    Weight mstWeight;  // 最小生成树的权值
    
    // 访问节点 v
    void visit(int v) {
        assert(!marked[v]);
        
        marked[v] = true;
        
        // 迭代器，访问该节点的邻边
        // 将和节点v相连接的所有未访问的边放入最小堆中
        typename Graph::adjIterator adj(G, v);
        
        for (WeightedGraphEdge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
            if (!marked[e->other(v)]) {
                pq.insert(*e);
            }
        }
    }
};

#endif
