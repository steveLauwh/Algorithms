#include <iostream>
#include "WeightedDenseGraph.h"
#include "WeightedSparseGraph.h"
#include "ReadWeightedGraph.h"

using namespace std;

// 测试有权图和有权图的读取
int main() {

    string filename = "test.txt";
    int V = 8;
    
    // Test Weighted Dense Graph，无向图
    DenseGraph<double> g1 = DenseGraph<double>(V, false);
    ReadGraph<DenseGraph<double>, double> readGraph1(g1, filename);
    g1.show();
    cout<<endl;

    // Test Weighted Sparse Graph
    SparseGraph<double> g2 = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph2(g2, filename);
    g2.show();
    cout<<endl;

    return 0;
}
