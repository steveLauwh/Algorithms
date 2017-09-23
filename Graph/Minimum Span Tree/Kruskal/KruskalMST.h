#ifndef KRUSKAL_MST_H_
#define KRUSKAL_MST_H_

#include <iostream>
#include <vector>
#include "MinHeap.h"
#include "UnionFind.h"
#include "WeightedGraphEdge.h"

using namespace std;

// Kruskal 算法
template <typename Graph, typename Weight>
class KruskalMST {
public:
    // 构造函数
    KruskalMST(Graph &graph) {
        // 将图中的所有边存放到一个最小堆中
        MinHeap<WeightedGraphEdge<Weight>> pq(graph.E());
        
        // 依次入最小堆
        for (int i = 0; i < graph.V(); i++) {
            typename Graph::adjIterator adj(graph, i);
            
            for (WeightedGraphEdge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
                if (e->V() < e->W()) {
                    pq.insert(*e);
                }
            }
        }
        
        // 创建一个并查集, 来查看已经访问的节点的连通情况
        UnionFind uf = UnionFind(graph.V());
        
        while (!pq.isEmpty() && mst.size() < graph.V() - 1) {
            // 从最小堆中依次从小到大取出所有的边
            WeightedGraphEdge<Weight> e = pq.extractMin();
            
            // 如果该边的两个端点是连通的, 说明加入这条边将产生环, 扔掉这条边
            if ( uf.isConnected( e.V(), e.W() ) ) {
                continue;
            }
            
            // 否则, 将这条边添加进最小生成树, 同时标记边的两个端点连通
            mst.push_back(e);
            uf.unionElements( e.v() , e.w() );
        }
        
        mstWeight = mst[0].wt();
        for (int i = 1; i < mst.size(); i++) {
            mstWeight += mst[i].wt();
        }
    }
    
    ~KruskalMST() {}
    
    // 返回最小生成树的所有边
    vector<WeightedGraphEdge<Weight>> mstEdges(){
        return mst;
    };

    // 返回最小生成树的权值
    Weight result(){
        return mstWeight;
    };

private:
    vector<WeightedGraphEdge<Weight>> mst;   // 最小生成树所包含的所有边
    Weight mstWeight;     // 最小生成树的权值
};

#endif


