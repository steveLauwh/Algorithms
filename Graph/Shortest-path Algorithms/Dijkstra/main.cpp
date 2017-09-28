#include <iostream>
#include "WeightedSparseGraph.h"
#include "ReadWeightedGraph.h"
#include "Dijkstra.h"

using namespace std;

int main() {

    string filename = "test.txt";
    int V = 5;

    WeightedSparseGraph<int> g = WeightedSparseGraph<int>(V, true);
    // Dijkstra最短路径算法同样适用于有向图
    //WeightedSparseGraph<int> g = WeightedSparseGraph<int>(V, false);
    ReadWeightedGraph<WeightedSparseGraph<int>, int> readGraph(g, filename);

    cout<<"Test Dijkstra:"<<endl<<endl;
    
    Dijkstra<WeightedSparseGraph<int>, int> dij(g, 0);
    
    for( int i = 0 ; i < V ; i ++ ) {
    
        if(dij.hasPathTo(i)){
            cout << "Shortest Path to " << i << " : " << dij.shortestPathTo(i) << endl;
            
            dij.showPath(i);
        }
        else
            cout << "No Path to " << i << endl;

        cout << "----------" << endl;
    }

    return 0;
}
