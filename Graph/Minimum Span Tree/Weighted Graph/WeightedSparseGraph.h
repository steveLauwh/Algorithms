#ifndef WEIGHTED_SPARSE_GRAPH_H
#define WEIGHTED_SPARSE_GRAPH_H

#include <iostream>
#include <cassert>
#include <vector>
#include "WeightedGraphEdge.h"

using namespace std;

// 稀疏图——用邻接表表示，带有权值
template <typename Weight>
class WeightedSparseGraph {
private:
    int n;  // 图的顶点
    int m;  // 图的边数
    bool directed; // 方向
    vector< vector<WeightedGraphEdge<Weight>*> > g;  // 邻接表的特点，用向量表示，如果没有边为NULL，还可以用链表表示

public:
    WeightedSparseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;  // 初始化没有任何边
        this->directed = directed;
        
        // g 初始化为 n 个空的 vector, 表示每一个 g[i] 都为空, 即没有任和边
        g = vector< vector<WeightedGraphEdge<Weight>*> >(n, vector<WeightedGraphEdge<Weight>*>());
    }

    ~WeightedSparseGraph() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < g[i].size(); j++) {
                delete g[i][j];
            }
        }
    }

    int V() {
        return n;  // 顶点数
    }

    int E() {
        return m;  // 边数
    }

    // 向图中添加一个边，权重为 weight
    void addEdge(int v, int w, Weight weight) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        g[v].push_back(new WeightedGraphEdge<Weight>(v, w, weight));  // 新添加一条边

        if (v != w && !directed) {  // 无向图
            g[w].push_back(new WeightedGraphEdge<Weight>(w, v, weight));
        }

        m++;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        for (unsigned int i = 0; i < g[v].size(); i++) {
            if (g[v][i]->other(v) == w)
                return true;
        }

        return false;
    }
    
    void show() {
        for(int i = 0; i < n; i ++) {
            cout << "vertex " << i << ":\t";

            for(int j = 0; j < g[i].size(); j ++)
                cout << "to: " << g[i][j]->W() << ", wt: " << g[i][j]->wt() << "\t";

            cout << endl;
        }
    }


    // 遍历邻边——迭代器
    class adjIterator {
    private:
        WeightedSparseGraph &G;
        int v;
        unsigned int index;

    public:
        adjIterator(WeightedSparseGraph &graph, int v) : G(graph) {
            this->v = v;
            this->index = 0;
        }
        
        ~adjIterator() {}

        // 返回图 G 中与顶点 v 相连接的第一个边
        WeightedGraphEdge<Weight>* begin() {
            index = 0;
            if (G.g[v].size()) {
                return G.g[v][index];
            }

            return NULL; // 存储权值，没有为 NULL
        }

        // 返回图 G 中与顶点 v 相连接的下一条边
        WeightedGraphEdge<Weight>* next() {
            index++;
            if (index < G.g[v].size()) {
                return G.g[v][index];
            }

            return NULL;
        }

        // 查看是否已经迭代完了图 G 中与顶点 v 相连接的所有顶点
        bool end() {
            return index >= G.g[v].size();
        }
    };
};

#endif
