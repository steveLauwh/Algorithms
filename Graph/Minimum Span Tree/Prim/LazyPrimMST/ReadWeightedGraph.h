#ifndef READ_WEIGHTED_GRAPH_H_
#define READ_WEIGHTED_GRAPH_H_

#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

template <typename Graph, typename Weight>
class ReadWeightedGraph {
public:
    // 从文件 filename 中读取有权图的信息, 存储进图 graph 中
    ReadWeightedGraph(Graph &graph, const string &filename) {
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
	    Weight weight;

	    s >> a >> b >> weight;
	    assert(a >= 0 && a < V);
            assert(b >= 0 && b < V);

	    graph.addEdge(a, b, weight);
        }
    }
};

#endif /* READGRAPH_H_ */

