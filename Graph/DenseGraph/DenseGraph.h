#ifndef DENSEGRAPH_H
#define DENSEGRAPH_H

#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

// 稠密图——用邻接矩阵表示
class DenseGraph {
private:
    int n;
    int m;
    bool directed;
    vector< vector<bool> > g; // 邻接矩阵的值用 0 和 1 表示

public:
    DenseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;

        for (int i = 0; i < n; i++) {
            g.push_back(vector<bool>(n, false));  // 矩阵初始都为 false
        }
    }

    ~DenseGraph() {

    }

    int V() {
        return n;
    }

    int E() {
        return m;
    }

    void addEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        if (hasEdge(v, w)) {
            return;
        }

        g[v][w] = true;

        if (!directed) {
            g[w][v] = true;  // 无向图
        }

        m++;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        return g[v][w];
    }
    
    void show() {
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {

                cout << g[i][j] << "\t";
            }

            cout << endl;
        }
    }

    class denseGraphIterator {
    private:
        DenseGraph &G;
        int v;
        int index;

    public:
        denseGraphIterator(DenseGraph &graph, int v) : G(graph) {
            this->v = v;
            this->index = -1;
        }

        int begin() {
            index = -1;
            return next();
        }

        int next() {
            for (index += 1; index < G.V(); index++) {
                if (G.g[v][index]) {
                    return index;    // 返回节点的值
                }
            }

            return -1;
        }

        int end() {
            return index >= G.V();
        }
    };

};

#endif
