#ifndef READGRAPH_H_
#define READGRAPH_H_

#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

template <typename Graph>
class ReadGraph {
public:
    ReadGraph(Graph &graph, const string &filename) {
	ifstream file(filename);
	string line;
	int V, E;

	assert(file.is_open());
	assert(getline(file, line)); // 文件第一行，V 和 E
	stringstream s(line);
	s >> V >> E;

	assert(V == graph.V());

	for (int i = 0; i < E; i++) {
	    assert(getline(file, line));
	    stringstream s(line);
	    
	    int a, b;

	    s >> a >> b;
	    assert(a >= 0 && a < V);
	    assert(b >= 0 && b < V);

	    graph.addEdge(a, b);
	}
    }
};

#endif /* READGRAPH_H_ */

