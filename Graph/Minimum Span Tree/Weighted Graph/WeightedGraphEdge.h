#ifndef WEIGHTED_GRAPH_EDGE_H
#define WEIGHTED_GRAPH_EDGE_H

#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class WeightedGraphEdge {
public:
    WeightedGraphEdge(int u, int v, T weight) {
        this->u = u;
        this->v = v;
        this->weight = weight;
    }
  
    WeightedGraphEdge() {}
    
    ~WeightedGraphEdge() {}
    
    int U() { return u;} // 第一个顶点
  
    int V() { return v;} // 第二个顶点
    
    T wt() {
        return weight; // 边的权值
    }
  
    // 求另一条边
    int other(int x) {
        assert(x == u || x == v);
        return x == u ? v : u;
    }
  
    // 输出边的信息
    friend ostream& operator<<(ostream &os, const WeightedGraphEdge &e) {
        os << e.u << " - " << e.v << " : " << e.weight;
        return os;
    }
  
    // 对边的权值的大小比较
    bool operator<(WeightedGraphEdge<T>& e) {
        return weight < e.wt();
    }
  
    bool operator<=(WeightedGraphEdge<T>& e) {
        return weight <= e.wt();
    }
  
    bool operator>(WeightedGraphEdge<T>& e) {
        return weight > e.wt();
    }
  
    bool operator>=(WeightedGraphEdge<T>& e) {
        return weight >= e.wt();
    }
    
    bool operator==(WeightedGraphEdge<T>& e) {
        return weight == e.wt();
    }
  
private:
    int u, v;  // 边的两个顶点
    T weight;  // 边的权值
};


#endif

