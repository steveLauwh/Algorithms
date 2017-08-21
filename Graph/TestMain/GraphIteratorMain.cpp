#include <iostream>
#include <ctime>
#include <cstdlib>
#include "SparseGraph.h"
#include "DenseGraph.h"

using namespace std;

#define N 10
#define M 50

int main() {
  srand(time(NULL));
  
  // Sparse Graph
  SparseGraph sparseGraph(N, false);
  
  for (int i = 0; i < M; i++) {
      int a = rand() % N;
      int b = rand() % N;
      
      sparseGraph.addEdge(a, b); // 增加邻边
  }
  
  // 遍历邻边 O(E)
  for (int v = 0; v < N; v++) {
      cout << v << " : ";
      
      SparseGraph::adjIterator it(sparseGraph, v);
      
      for (int w = it.begin(); !it.end(); w = it.next()) {
          cout << w << " ";
      }
      
      cout << endl;
  }
  
  cout << "----------------------------------------------" << endl;
  
  // Dense Graph
  DenseGraph denseGraph(N, false);
  
  for (int i = 0; i < M; i++) {
      int a = rand() % N;
      int b = rand() % N;
      
      denseGraph.addEdge(a, b); // 增加邻边
  }
  
  // 遍历邻边 O(V^2)
  for (int v = 0; v < N; v++) {
      cout << v << " : ";
      
      DenseGraph::adjIterator it(denseGraph, v);
      
      for (int w = it.begin(); !it.end(); w = it.next()) {
          cout << w << " ";
      }
      
      cout << endl;
  }
  
  return 0;
}
