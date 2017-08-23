#ifndef FINDPATH_H_
#define FINDPATH_H_

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

using namespace std;

template <typename Graph>
class FindPath {
private:
    Graph &g;
    bool *visited;  // 记录 DFS 过程中的节点是否被访问
    int source;  // 寻路的起始点
    int *from;   //  from[i] 表示查找的路径上 i 的上一个节点
    
    // 图的深度优先遍历
    void dfs(int v) {
        visited[v] = true;
        
        typename Graph::adjIterator adj(g, v);
        for( int i = adj.begin() ; !adj.end() ; i = adj.next() ) {
            if ( !visited[i] ) {
                from[i] = v;  // 记录
                dfs(i);
            }
        }
    }
    
public:
    FindPath(Graph &graph, int s) : g(graph) {
        assert(s >= 0 && s < g.V());
        
        visited = new bool[g.V()];
        from = new int[g.V()];
        
        for (int i = 0; i < g.V(); i++) {
            visited[i] = false;
            from[i] = -1;
        }
        
        this->source = s;
        
        // 寻路
        dfs(s);
    }
    
    ~FindPath() {
        delete[] visited;
        delete[] from;
    }
    
    // 查询从 s 到 t 是否有路径
    bool hasPath(int t) {
        assert(t>= 0 && t < g.V());
        
        return visited[t];
    }
    
    // 查询 s 到 t 的路径，存放在 vector 中
    void path(int t, vector<int> &v) {
        assert(hasPath(t));
        
        stack<int> s;
        
        // 通过 from 数组逆向查找到从 s 到 t 的路径, 存放到栈中
        while (t != -1) { // 源点 s 的 from[s] 是 -1
            s.push(t);
            t = from[t];
        }
        
        // 从栈中取出，顺序的从 s 到 t 的路径，存放到 vector 中
        v.clear();
        
        while (!s.empty()) {
            v.push_back(s.top());   
            s.pop();  
        }
    }
    
    // 打印出从 s 点到 t 点的路径
    void showPath(int t) {
        assert(hasPath(t));
        
        vector<int> vec;
        
        path(t, vec);
        
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i];
            
            if (i == vec.size() - 1) {
                cout << endl;
            }
            else {
                cout << " -> ";
            }
        }
    }
};


#endif
