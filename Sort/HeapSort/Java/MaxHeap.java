package com.sort.maxheapsort;

public class MaxHeap {

  private int[] data;     // 数组存储堆
  private int count;     // 节点数目
  private int capacity; // 容量
  
  // 构造函数
  public MaxHeap(int capacity) {
      data = new int[capacity + 1];
      count = 0;
      this.capacity = capacity;
  }
  
  // heapify 过程，给定数组建堆
  public MaxHeap(int arr[]) {
      int n = arr.length;
    
      data = new int[n+1]; // data[0] 不保存节点
      capacity = n;
    
      for (int i = 0; i < n; i++) {
          data[i+1] = arr[i];
      }
    
      count = n;
      
      // 非叶子节点进行调整
      for (int i = count/2; i>=1; i--) {
          shiftDown(i);
      }
  }
  
  public boolean isEmpty() {
      return count == 0;
  }
  
  public int size() {
      return count;
  }
  
  public int getMax() {
      return data[1];
  }
  
  private void swap(int i, int j) {
      int temp = data[i];
      data[i] = data[j];
      data[j] = temp;
  }
  
  // Shift Up 
  private void shiftUp(int i) {
      while (i > 1 && data[i/2] < data[i]) {
          swap(i, i/2);
          i = i/2;
      }
  }
  
  // Shift Down
  private void shiftDown(int i) {
      while (2*i <= count) {
          int j = 2*i;
          if (j + 1 <= count && data[j+1] > data[j]) {
              j++;
          }
          
          // 否则 data[j] > data[j+1], 同时父节点大于最大的子节点，直接退出
          if (data[i] > data[j]) {
              break;
          }
          
          // data[i] 是 data[2*k]和data[2*k+1]中的最大值
          swap(i, j);
          
          i = j;
      }
  }
  
  // 插入
  public void insert(int item) {
      data[count+1] = item;
      count++;
      shiftUp(count);
  }
  
  // 取出最大元素
  public int extractMax() {
      int ret = data[1];
      swap(1, count);
      count--;
      shiftDown(1);
    
      return ret;
  }  
}
