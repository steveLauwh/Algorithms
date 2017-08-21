#ifndef SPARSEGRAPH_H
#define SPARSEGRAPH_H

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// 稀疏图——用邻接表表示
class SparseGraph {
private:
    int n;  // 图的顶点
    int m;  // 图的边
    bool directed; // 方向
    vector< vector<int> > g;  // 邻接表的特点，还可以用链表表示

public:
    SparseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;

        for (int i = 0; i < n; i++) {
            g.push_back(vector<int>()); // 初始每行都为空
        }
    }

    ~SparseGraph() {

    }

    int V() {
        return n;  // 顶点数
    }

    int E() {
        return m;  // 边数
    }

    void addEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        g[v].push_back(w);

        if (v != w && !directed) {  // 无向图
            g[w].push_back(v);
        }

        m++;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        for (unsigned int i = 0; i < g[v].size(); i++) {
            if (g[v][i] == w)
                return true;
        }

        return false;
    }
    
    void show() {
        for(int i = 0; i < n; i ++) {
            cout << "vertex " << i << ":\t";

            for(int j = 0; j < g[i].size(); j ++)
                cout << g[i][j] << "\t";

            cout << endl;
        }
    }


    // 遍历邻边——迭代器
    class adjIterator {
    private:
        SparseGraph &G;
        int v;
        unsigned int index;

    public:
        adjIterator(SparseGraph &graph, int v) : G(graph) {
            this->v = v;
            this->index = 0;
        }

        int begin() {
            index = 0;
            if (G.g[v].size()) {
                return G.g[v][index];
            }

            return -1;
        }

        int next() {
            index++;
            if (index < G.g[v].size()) {
                return G.g[v][index];
            }

            return -1;
        }

        bool end() {
            return index >= G.g[v].size();
        }
    };


};

#endif
