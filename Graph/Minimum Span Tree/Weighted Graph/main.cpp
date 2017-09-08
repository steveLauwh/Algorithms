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
    WeightedDenseGraph<double> g1 = WeightedDenseGraph<double>(V, false);
    ReadWeightedGraph<WeightedDenseGraph<double>, double> readGraph1(g1, filename);
    g1.show();
    cout<<endl;

    // Test Weighted Sparse Graph
    WeightedSparseGraph<double> g2 = WeightedSparseGraph<double>(V, false);
    ReadWeightedGraph<ReadWeightedGraph<double>, double> readGraph2(g2, filename);
    g2.show();
    cout<<endl;

    return 0;
}
