#ifndef __BELLMAN_FORD_H_
#define __BELLMAN_FORD_H_

#include <stack>
#include <vector>
#include "WeightedGraphEdge.h"

using namespace std;

// BellmanFord 算法求解最短路径
template <typename Graph, typename Weight>
class BellmanFord {
public:
    // 构造函数
    BeallmanFord(Graph &graph, int s) : G(graph) {
        this->s = s;
        distTo = new Weight[G.V()];
        
        // 初始化所有的节点 s 都不可到达，由 from 数组来表示
        for (int i = 0; i < G.V(); i++) {
            from.push_back(NULL);
        }
        
        // 设置 distTo[s] = 0, 并且让 from[s] 不为 NULL, 表示初始 s 节点可达且距离为 0
        distTo[s] = Weight();
        from[s] = new WeightedGraphEdge<Weight>(s, s, 0);
        
        // Bellman-Ford的过程
        // 进行 V-1 次循环, 每一次循环求出从起点到其余所有点, 最多使用 pass 步可到达的最短距离
        for (int pass = 1; pass < G.V(); pass++) {
            // 每次循环中对所有的边进行一遍松弛操作
            // 遍历所有边的方式是先遍历所有的顶点, 然后遍历和所有顶点相邻的所有边
            for (int i = 0; i < G.V(); i++) {
                // 使用我们实现的邻边迭代器遍历和所有顶点相邻的所有边
                typename Graph::adjIterator adj(G, i);
                
                for (WeightedGraphEdge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
                    // 对于每一个边首先判断 e->v() 可达
                    // 之后看如果 e->w() 以前没有到达过， 显然我们可以更新distTo[e->w()]
                    // 或者 e->w() 以前虽然到达过, 但是通过这个e我们可以获得一个更短的距离, 即可以进行一次松弛操作, 我们也可以更新distTo[e->w()]
                    if ( from[e->V()] && (!from[e->W()] || distTo[e->V()] + e->wt() < distTo[e->W()]) ) {
                        distTo[e->W()] = distTo[e->V()] + e->wt();
                        from[e->W()] = e;
                    }               
                }
            }
        }
        
        hasNegativeCycle = detectNegativeCycle();
    }
    
    // 析构函数
    ~BellmanFord() {
        delete[] distTo;
        delete from[s];
    }
    
    // 返回图中是否有负权环
    bool negativeCycle() {
        return hasNegativeCycle;
    }
    
    // 返回从 s 点到 w 点的最短路径长度
    Weight shortestPathTo(int w) {
        assert(w >= 0 && w < G.V());
        assert(!hasNegativeCycle);
        assert(hasPathTo(w));
        
        return distTo[w];
    }
    
    // 判断从 s 点到 w 点是否连通
    bool hasPathTo(int w) {
        assert(w >= 0 && w < G.V());
        
        return from[w] != NULL;
    }
    
    // 寻找从 s 到 w 的最短路径，将整个路径经过的边放在 vec 中
    void shortestPath(int w, vector<WeightedGraphEdge<Weight>> &vec) {
        assert(w >= 0 && w < G.V());
        assert(!hasNegativeCycle);
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
        assert(!hasNegativeCycle);
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
    Weight* distTo;   // distTo[i] 存储从起始点 s 到 i 的最短路径长度
    vector<WeightedGraphEdge<Weight>*> from;  // from[i] 记录最短路径中，到达 i 点的边是哪一条
    bool hasNegativeCycle;  // 标记图中是否有负权环
    
    // 判断图中是否有负权环
    bool detectNegativeCycle(){

        for( int i = 0 ; i < G.V() ; i ++ ){
            typename Graph::adjIterator adj(G,i);
            for( Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next() )
                if( from[e->V()] && distTo[e->V()] + e->wt() < distTo[e->W()] )
                    return true;
        }

        return false;
    }
};

#endif
