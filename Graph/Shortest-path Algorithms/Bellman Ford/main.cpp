#include <iostream>
#include "WeightedSparseGraph.h"
#include "ReadWeightedGraph.h"
#include "BellmanFord.h"

using namespace std;

// 测试Bellman-Ford算法
int main() {

    string filename = "test.txt";
    int V = 5;

    // 有向图
    WeightedSparseGraph<int> g = WeightedSparseGraph<int>(V, true);
    ReadWeightedGraph<WeightedSparseGraph<int>, int> readGraph(g, filename);

    cout<<"Test Bellman-Ford: "<<endl<<endl;
    BellmanFord<WeightedSparseGraph<int>, int> bellmanFord(g, 0);
    if( bellmanFord.negativeCycle() )
        cout<<"The graph contain negative cycle!"<<endl;
    else
        for( int i = 1 ; i < V ; i ++ ) {
            if (bellmanFord.hasPathTo(i)) {
                cout << "Shortest Path to " << i << " : " << bellmanFord.shortestPathTo(i) << endl;
                bellmanFord.showPath(i);
            }
            else
                cout << "No Path to " << i << endl;

            cout << "----------" << endl;
        }

    return 0;
}
