package com.sort.minheapsort;

public class MinHeap {
    private int[] data;
    private int capacity;
    private int count;
  
    public MinHeap(int capacity) {
        data = new int[capacity + 1];
        count = 0;
        this->capacity = capacity;
    }
  
    // 构造函数, 通过一个给定数组创建一个最小堆, heapify过程
    // 对非叶子节点进行 shift down 操作
    public MinHeap(int[] arr) {
        int arrLength = arr.length;
        data = new int[arrLength+1];
        capacity = arrLength;
        
        for (int i = 0; i < arrLength; i++) {
            data[i+1] = arr[i];
        }
      
        count = arrLength;
        
        // 非叶子节点
        for (int i = count/2; i >= 1; i--) {
            shiftDown(i);
        }
    }
  
    public boolean isEmpty() {
        return count == 0;
    }
  
    public int size() {
        return count;
    }
  
    public int getMin() {
        return data[1];
    }
  
    private void swap(int i, int j) {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
  
    // shift up
    private void shiftUp(int i) {
        while (i > 1 && data[i/2] > data[i]) {
            swap(i, i/2);
            i /= 2;
        }
    }
  
    // shift down
    private void shiftDown(int i) {
        while (2*i <= count) {
            int j = 2*i;
            
            if (j+1 <= count && data[j+1] < data[j]) {
                j++;
            }
            
            if (data[i] < data[j]) {
                break;
            }
            
            swap(data[i], data[j]);
          
            i = j;
        }
    }
  
    // 向最小堆中插入一个新的元素 element
    public void insert(int element) {
        data[count+1] = element;
        count++;
        shiftUp(count);
    }
  
    // 从最小堆中取出堆顶元素, 即堆中所存储的最小数据
    
    public int extractMin() {
        int ret = data[1];
        swap(1, count);
        count--;
        shiftDown(1);
      
        return ret;
    }
}
