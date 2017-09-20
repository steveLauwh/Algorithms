#include <iostream>
#include <iomanip>
#include "WeightedDenseGraph.h"
#include "WeightedSparseGraph.h"
#include "ReadWeightedGraph.h"
#include "LazyPrimMST.h"

using namespace std;

// 娴嬭瘯鏈�灏忕敓鎴愭爲绠楁硶
int main() {

    string filename = "test.txt";
    int V = 8;

    WeightedSparseGraph<double> g = WeightedSparseGraph<double>(V, false);
    ReadWeightedGraph<WeightedSparseGraph<double>, double> readGraph(g, filename);

    // Test Lazy Prim MST
    cout << "Test Lazy Prim MST:" << endl;
    LazyPrimMST<WeightedSparseGraph<double>, double> lazyPrimMST(g);
    vector<WeightedGraphEdge<double>> mst = lazyPrimMST.mstEdges();
    for( unsigned int i = 0 ; i < mst.size() ; i ++ )
        cout << mst[i] << endl;
    
    cout << "The MST weight is: " << lazyPrimMST.result() << endl;

    cout << endl;

    return 0;
}
