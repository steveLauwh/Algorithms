#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "Component.h"

using namespace std;

int main() {

    string filename = "test.txt";

    SparseGraph g1(10, false);
    ReadGraph<SparseGraph> readGraph1(g1, filename);
    Component<SparseGraph> component1(g1);
    cout << "test.txt, Component Count: " << component1.count() << endl;

    cout << endl;

    DenseGraph g2(10, false);
    ReadGraph<DenseGraph> readGraph2(g2, filename);
    Component<DenseGraph> component2(g2);
    cout<<"test.txt, Component Count: "<<component2.count()<<endl;

    return 0;
}

