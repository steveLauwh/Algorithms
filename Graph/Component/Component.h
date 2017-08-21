#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <iostream>
#include <cassert>

using namespace std;

// 求无权图的联通分量
template <typename Graph>
class Component {
private:
	Graph &g;
	bool *visited;  // 记录 DFS 过程中顶点是否被遍历
	unsigned int counts;   // 记录联通分量的个数
	int *id;    // 每个顶点所对应的联通分量标记

	// 图的深度优先遍历
	void dfs(int v) {
		visited[v] = true;
		id[v] = counts;

		typename Graph::adjIterator adj(g, v);

		for (int i = adj.begin(); !adj.end(); i = adj.next()) {
			if (!visited[i]) {
				dfs(i);
			}
		}
	}

public:
	// 构造函数，求出无权图的联通分量
	Component(Graph &graph) : g(graph) {
		visited = new bool[g.V()];
		id = new int[g.V()];
		counts = 0;

		for (int i = 0; i < g.V(); i++) {
			visited[i] = false;
			id[i] = -1;
		}

		// 图的联通分量
		for (int i = 0; i < g.V(); i++) {
			if (!visited[i]) {
				dfs(i);
				counts++;
			}
		}
	}

	~Component() {
		delete[] visited;
		delete[] id;
	}

	int count() {
		return counts;
	}

	// 查询顶点 v 和顶点 w 是否联通
	bool isConnected(int v, int w) {
		assert(v >= 0 && w < g.V());
		assert(w >= 0 && w < g.V());

		return id[v] == id[w];
	}
};

#endif /* COMPONENT_H_ */
