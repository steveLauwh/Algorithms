#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"

using namespace std;

int main() {

    string filename = "test.txt";

    SparseGraph g1(10, false);
    ReadGraph<SparseGraph> readGraph1(g1, filename);
    g1.show();

    cout << endl;

    DenseGraph g2(10, false);
    ReadGraph<DenseGraph> readGraph2(g2, filename);
    g2.show();

    return 0;
}

