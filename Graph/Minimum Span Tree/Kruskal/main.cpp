#include <iostream>
#include <iomanip>
#include "WeightedDenseGraph.h"
#include "WeightedSparseGraph.h"
#include "ReadWeightedGraph.h"
#include "KruskalMST.h"

using namespace std;

// Kruskal MST
int main() {

    string filename = "test.txt";
    int V = 8;

    WeightedSparseGraph<double> g = WeightedSparseGraph<double>(V, false);
    ReadWeightedGraph<WeightedSparseGraph<double>, double> readGraph(g, filename);

    // Test Kruskal MST
    cout << "Test Prim MST:" << endl;
    KruskalMST<WeightedSparseGraph<double>, double> kruskalMST(g);
    vector<WeightedGraphEdge<double>> mst = kruskalMST.mstEdges();
    
    for( unsigned int i = 0 ; i < mst.size() ; i ++ )
        cout << mst[i] << endl;
    
    cout << "The Kruskal MST weight is: " << primMST.result() << endl;

    cout << endl;

    return 0;
}
