#ifndef UNIONFIND_H_
#define UNIONFIND_H_

#include <iostream>
#include <cassert>

using namespace std;

// Quick Union + rank + path compression
class UnionFind {
public:
    // 构造函数
    UnionFind(int count) {
	parent = new int[count];
	rank = new int[count];
	this->count = count;

	for (int i = 0; i < count; i++) {
	    parent[i] = i;
	    rank[i] = 1;
	}
    }

    ~UnionFind() {
	delete[] parent;
	delete[] rank;
    }
    
    // 查找过程，O(h), h 为树的高度
    int find(int p) {
	assert(p >= 0 && p < count);

	// path compression
	while (p != parent[p]) {
	    parent[p] = parent[parent[p]];
	    p = parent[p];
	}

	return p;
    }

    // 查看元素 p 和 q 是否所属一个集合
    bool isConnected(int p, int q) {
	return find(p) == find(q);
    }

    // 合并元素 p 和元素 q 所属的集合
    void unionElements(int p, int q) {
	int pRoot = find(p);
	int qRoot = find(q);

	if (pRoot == qRoot) {
	    return;
        }

        // 根据两个元素所在树的元素个数不同判断合并方向
    	// 将元素个数少的集合合并到元素个数多的集合上
    	if (rank[pRoot] < rank[qRoot]) {
	    parent[pRoot] = qRoot;
    	} else if( rank[qRoot] < rank[pRoot]) {
	    parent[qRoot] = pRoot;
    	} else { // rank[pRoot] == rank[qRoot]
	    parent[pRoot] = qRoot;
	    rank[qRoot] += 1;   
    	}
    }

private:
    int *rank;	 // rank[i]表示以i为根的集合所表示的树的层数
    int *parent; // parent[i]表示第i个元素所指向的父节点
    int count;   // 数据个数
};

#endif /* UNIONFIND_H_ */
