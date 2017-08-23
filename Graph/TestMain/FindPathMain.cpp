#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "FindPath.h"

using namespace std;

int main() {

    string filename = "test.txt";
    SparseGraph g = SparseGraph(10, false);
    ReadGraph<SparseGraph> readGraph(g, filename);
    g.show();
    cout<<endl;

    FindPath<SparseGraph> path(g, 0);
    cout<<"Path from 0 to 7 : " << endl;
    path.showPath(7);

    return 0;
}
