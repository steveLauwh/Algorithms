#ifndef __MINHEAP_H_
#define __MINHEAP_H_

#include <algorithm>
#include <cassert>

using namespace std;

// 最小堆
template <typename T>
class MinHeap {
public:
    // 构造函数，构造一个空堆，可容纳 capacity 个元素
    MinHeap(int capacity) {
        data = new T[capacity + 1];
        count = 0;
        this->capacity = capacity;
    }
    
    // 构造函数，通过给定一个数组，创建一个最小堆，O(n)
    MinHeap(T arr[], int n) {
        data = new T[n + 1];
        capacity = n;
        
        for (int i = 0; i < n; i++) {
            data[i + 1] = arr[i];
        }
        
        count = n;
        
        for (int i = count / 2; i >= 1; i--) {
            shiftDown(i);
        }
    }
    
    ~MinHeap() {
        delete[] data;
    }
    
    int size() {
        return count;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    // 向最小堆中插入一个新的元素
    void insert(T item) {
        assert(count + 1 <= capacity);
        data[count + 1] = item;
        
        shiftUp(count + 1);
        
        count++;
    }
    
    // 从最小堆中取出堆顶元素
    T extractMin() {
        assert(count > 0);
        T ret = data[1];
        swap(data[1], data[count]);
        count--;
        
        shiftDown(1);
        
        return ret;
    }
    
    // 获取最小堆中的堆顶元素
    T getMin() {
        assert(count > 0);
        return data[1];
    }

private:
    T *data;
    int count;
    int capacity;
    
    void shiftUp(int k) {
        while (k > 1 && data[k/2] > data[k]) {
            swap(data[k/2], data[k]);
            k /= 2;
        }
    }
    
    void shiftDown(int k) {
        while (2*k <= count) {
            int j = 2*k;
            if (j + 1 <= count && data[j+1] < data[j]) {
                j++;
            }
            
            if (data[k] <= data[j])
                break;
            
            swap(data[k], data[j]);
            
            k = j;
        }
    }
};

#endif
