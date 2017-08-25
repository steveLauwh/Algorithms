#include <iostream>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "FindPath.h"
#include "ReadGraph.h"
#include "ShortestPath.h"

using namespace std;

int main() {
    string filename = "test.txt";
    
    SparseGraph g(10, false);
    
    ReadGraph<SparseGraph> readGraph(g, filename);
    
    g.show();
    
    cout << endl;
    
    // 比较使用深度优先遍历和广度优先遍历获得路径的不同
    // 广度优先遍历获得的是无权图的最短路径
    FindPath<SparseGraph> dfs(g, 0);
    cout<<"DFS : ";
    dfs.showPath(4);

    ShortestPath<SparseGraph> bfs(g, 0);
    cout<<"BFS : ";
    bfs.showPath(4);
    
    return 0;
}
