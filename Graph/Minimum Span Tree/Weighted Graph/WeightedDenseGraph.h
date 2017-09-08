#ifndef WEIGHTED_DENSE_GRAPH_H
#define WEIGHTED_DENSE_GRAPH_H

#include <vector>
#include <iostream>
#include <cassert>
#include "WeightedGraphEdge.h"

using namespace std;

// 稠密图——用邻接矩阵表示
template <typename Weight>
class WeightedDenseGraph {
private:
    int n;  // 图的顶点数
    int m;  // 图的边数
    bool directed;
    vector< vector<WeightedGraphEdge<Weight> *> > g; // 邻接矩阵的值用 0 和 1 表示

public:
    WeightedDenseGraph(int n, bool directed) {
        assert(n >= 0);
        this->n = n;
        this->m = 0;
        this->directed = directed;

        // g初始化为 n*n 的矩阵, 每一个 g[i][j] 指向一个边的信息, 初始化为NULL
        g = vector<vector<WeightedGraphEdge<Weight> *> >(n, vector<Edge<Weight> *>(n, NULL));
    }

    ~WeightedDenseGraph() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] != NULL)
                    delete g[i][j];
            }
        }
    }

    int V() {
        return n;
    }

    int E() {
        return m;
    }

    // 向图中添加一个边, 权值为 weight
    void addEdge(int v, int w, Weight weight) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        if (hasEdge(v, w)) {
            delete g[v][w];  // 如果从v到w已经有边, 删除这条边
            
            if (v != w && !directed)
                delete g[w][v];
            m--;
        }

        g[v][w] = new WeightedGraphEdge<Weight>(v, w, weight); // 新增一条边

        if (v != w && !directed) {
            g[w][v] = new WeightedGraphEdge<Weight>(w, v, weight);  // 无向图
        }

        m++;
    }

    // 验证图中是否有从 v 到 w 的边
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        return g[v][w] != NULL;
    }
    
    // 显示稠密图的信息
    void show() {
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                if (g[i][j]) {
                    cout << g[i][j]->wt() << "\t";
                } else {
                    cout << "NULL" << "\t";
                }
            }

            cout << endl;
        }
    }

    class adjIterator {
    private:
        WeightedDenseGraph &G;
        int v;
        int index;

    public:
        adjIterator(WeightedDenseGraph &graph, int v) : G(graph) {
            this->v = v;
            this->index = -1;
        }
        
        ~adjIterator() {}

        // 返回图 G 中与顶点 v 相连接的第一个边
        WeightedGraphEdge<Weight>* begin() {
            index = -1;
            return next();
        }

        // 返回图 G 中与顶点 v 相连接的下一个边
        WeightedGraphEdge<Weight>* next() {
            for (index += 1; index < G.V(); index++) {
                if (G.g[v][index]) {
                    return G.g[v][index];    // 返回节点的值
                }
            }

            return NULL;
        }

        // 查看是否已经迭代完了图 G 中与顶点 v 相连接的所有边
        bool end() {
            return index >= G.V();
        }
    };

};

#endif
