package com.sort.maxheapsort;

import com.sort.maxheapsort.MaxHeap;

public class MaxHeapSort {
    private MaxHeapSort() {}
    
    // 对整个arr数组使用HeapSort1排序
    // HeapSort1, 将所有的元素依次添加到堆中, 在将所有元素从堆中依次取出来, 即完成了排序
    // 无论是创建堆的过程, 还是从堆中依次取出元素的过程, 时间复杂度均为O(nlogn)
    // 整个堆排序的整体时间复杂度为O(nlogn)
    public static void heapSort1(int[] arr) {
        int arrLength = arr.length;
        
        MaxHeap maxHeap = new MaxHeap(arrLength);
        
        for (int i = 0; i < arrLength; i++) {
            maxHeap.insert(arr[i]);
        }
        
        for (int i = arrLength - 1; i >= 0; i--) {
            arr[i] = maxHeap.extractMax();
        }
    }
    
    // 对整个arr数组使用 HeapSort2 排序
    // HeapSort2, 借助我们的 heapify 过程创建堆
    // 此时, 创建堆的过程时间复杂度为O(n), 将所有元素依次从堆中取出来, 实践复杂度为O(nlogn)
    // 堆排序的总体时间复杂度依然是O(nlogn), 但是比HeapSort1性能更优, 因为创建堆的性能更优
    public static void heapSort2(int[] arr) {
        int arrLength = arr.length;
        
        MaxHeap maxHeap = new MaxHeap(arr);
        
        for (int i = arrLength - 1; i >= 0; i--) {
            arr[i] = maxHeap.extractMax();
        }
    }
    
    public static void main(String[] args) {
        int[] arr = {2, 5, 11, 16, 3, 4, 19, 40, 23};
        
        heapSort1(arr);
        
        for (int item : arr) {
            System.out.print(item + " ");
        }       
    }    
}
