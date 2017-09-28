#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include "WeightedGraphEdge.h"
#include "IndexMinHeap.h"

using namespace std;

// Dijkstra 算法--最短路径算法
template<typename Graph, typename Weight>
class Dijkstra {
public:
    Dijkstra(Graph &graph, int s) : G(graph) {
        assert(s >= 0 && s < G.V());
        this->s = s;
        distTo = new Weight[G.V()];
        marked = new bool[G.V()];
        
        for (int i = 0; i < G.V(); i++) {
            distTo[i] = Weight();
            marked[i] = false;
            from.push_back(NULL);
        }
        
        // Dijkstra
        // 使用索引堆记录当前找到的到达每个顶点的最短距离
        IndexMinHeap<Weight> ipq(G.V());
        
        distTo[s] = Weight();  // 从 s 点开始
        from[s] = new WeightedGraphEdge<Weight>(s, s, 0);
        
        ipq.insert(s, distTo[s]);
        
        marked[s] = true;
        
        while (!ipq.isEmpty()) {
            int v = ipq.extractMinIndex();
            
            // distTo[v] 就是 s 到 v 的最短距离
            marked[v] = true;
            
            // 对 v 的所有相邻节点进行更新
            typename Graph::adjIterator adj(G, v);
            
            for (WeightedGraphEdge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
                int w = e->other(v);
                
                // 如果从 s 点到 w 点的最短路径还没有找到
                if (!marked[w]) {
                     // 如果 w 点以前没有访问过,
                    // 或者访问过, 但是通过当前的 v 点到 w 点距离更短, 则进行更新
                    if (from[w] == NULL || distTo[v] + e->wt() < distTo[w]) {
                        distTo[w] = distTo[v] + e->wt();
                        
                        from[w] = e;
                        
                        if (ipq.contain(w)) {
                            ipq.change(w, distTo[w]);
                        } else {
                            ipq.insert(w, distTo[w]);
                        }
                    }
                }
            }
        }
        
    }
    
    ~Dijkstra() {
        delete[] distTo;
        delete[] marked;
        delete from[0];
    }
    
    // 返回从 s 点到 w 点的最短路径长度
    Weight shortestPathTo(int w) {
        assert(w >= 0 && w < G.V());
        assert(hasPathTo(w));
        
        return distTo[w];
    }
    
    // 判断从 s 点到 w 点是否连通
    bool hasPathTo(int w) {
        assert(w >= 0 && w < G.V());
        
        return marked[w];
    }
    
    // 寻找从 s 到 w 的最短路径，将整个路径经过的边存放在 vec 中
    void shortestPath(int w, vector<WeightedGraphEdge<Weight>> &vec) {
        assert(w >= 0 && w < G.V());
        assert(hasPathTo(w));
        
        // 通过 from 数组逆向查找到从 s 到 w 的路径, 存放到栈中
        stack<WeightedGraphEdge<Weight>*> s;
        WeightedGraphEdge<Weight> *e = from[w];
        
        while (e->V() != this->s) {
            s.push(e);
            e = from[e->V()];
        }
        
        s.push(e);
        
        // 从栈中依次取出元素, 获得顺序的从 s 到 w 的路径
        while (!s.empty()) {
            e = s.top();
            vec.push_back(*e);
            s.pop();
        }
    }
    
    // 打印出从 s 点到 w 点的路径
    void showPath(int w) {
        assert(w >= 0 && w < G.V());
        assert(hasPathTo(w));
        
        vector<WeightedGraphEdge<Weight>> vec;
        
        shortestPath(w, vec);
        
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i].V() << " -> ";
            
            if (i == vec.size() - 1) {
                cout << vec[i].W() << endl;
            }
        }
    }

private:
    Graph &G;   // 图的引用
    int s;      // 起始点
    Weight *distTo;   // distTo[i]存储从起始点 s 到 i 的最短路径长度
    bool *marked;     // 标记数组, 在算法运行过程中标记节点 i 是否被访问
    vector<WeightedGraphEdge<Weight>*> from;  // from[i] 记录最短路径中, 到达 i 点的边是哪一条
};

#endif
