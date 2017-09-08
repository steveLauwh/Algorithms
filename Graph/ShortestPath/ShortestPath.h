#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

// 使用BFS，求无权图的最短路径
template <typename Graph>
class ShortestPath {
public:
    // 构造函数, 寻找无权图从 s 点到其他点的最短路径
    ShortestPath(Graph &g, int s) : G(g) {
        assert(s >= 0 && s < g.V());
        
        visited = new bool[g.V()];
        from = new int[g.V()];
        order = new int[g.V()];
        
        for (int i = 0; i < g.V(); i++) {
            visited[i] = false;
            from[i] = -1;
            order[i] = -1;
        }
        
        this->s = s;
        
        // BFS 广度优先遍历，使用队列实现
        queue<int> q;
        
        q.push(s);
        visited[s] = true;
        order[s] = 0; // 距离
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            typename Graph::adjIterator adj(G, v);
            for (int i = adj.begin(); !adj.end(); i = adj.next()) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                    from[i] = v;
                    order[i] = order[v] + 1;
                }    
            }
        }
    
    }
    
    // 析构函数
    ~ShortestPath() {
        delete[] visited;
        delete[] from;
        delete[] order;
    }
    
    // 查询从 s 点到 w 点是否有路径
    bool hasPath(int w) {
        assert(w >= 0 && w < G.V());
        return visited[w];
    }
    
    // 查询从 s 点到 w 点的路径, 存放在 vector 中
    // from[w] 表示到 w 点的上一个节点
    // 通过 from 数组逆向查找到从 s 到 w 的路径, 存放到栈中
    void path(int w, vector<int> &vec) {
        assert(w >= 0 && w < G.V());
        
        stack<int> s;
        
        // 根节点是没有父节点，默认初值为 -1，利用这个条件循环
        while (w != -1) {
            s.push(w);
            w = from[w];
        }
        
        // 从栈中依次取出元素, 获得顺序的从 s 到 w 的路径
        vec.clear();
        while (!s.empty()) {
            vec.push_back(s.top());
            s.pop();
        }
    }
    
    // 打印出从 s 点到 w 点的路径
    void showPath(int w) {
        assert(w >= 0 && w < G.V());
        
        vector<int> vec;
        
        path(w, vec);
        
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i];
            
            if (i == vec.size() - 1) {
                cout << endl;
            } else {
                cout << " -> ";
            }
        }
    }
    
    // 查看从 s 点到 w 点的最短路径长度
    int length(int w) {
        assert(w >= 0 && w < G.V());
        
        return order[w];
    }

private:
    Graph &G;
    int s;  // 起始节点
    bool *visited; // 使用 BFS 遍历节点是否被访问
    int *from;  // 记录路径, from[i] 表示查找的路径上 i 的上一个节点
    int *order;  // 记录路径中节点的次序。order[i]表示i节点在路径中的次序。  
};


#endif
