/* 基本快排 和 双路快排
 * Java 实现
 */

package com.sort.quicksort;

public class QuickSort {
    private QuickSort() {}
  
    private static void swap(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    // partition1: 一个索引遍历，找出 pivotIndex
    // 对 arr[low...high] 进行 partition 操作
    // 返回 pivotIndex, 使得 arr[low...pivotIndex-1] < arr[pivotIndex] ; arr[pivotIndex+1...high] > arr[pivotIndex]
    private static int partition1(int arr[], int low, int high) {
        // 1. 第一个元素为基准
        int e = arr[low];
      
        // 2. 初始化基准索引 pivotIndex
        int pivotIndex = low;  // arr[low+1...pivotIndex] < e ; arr[pivotIndex+1...i) > e
        
        // 3. 遍历
        for (int i = low + 1; i <= high; i++)
        {
            // 待排序的元素小于基准，就将基准索引指向的元素与待排序的元素交换
            if (arr[i] < e)
            {
                pivotIndex++;
                swap(arr, i, pivotIndex);                
            }
        }
        
        // 4. 基准元素 与 基准索引指向的元素 进行交换
        // 形成 arr[low...pivotIndex-1] < e; arr[pivotIndex] == e; arr[pivotIndex+1...high] > e 
        swap(arr, low, pivotIndex);
      
        return pivotIndex;
    }
    
    // partition2: 两个索引，一前一后，找出 pivotIndex
    // 返回 pivotIndex, 使得 arr[low...pivotIndex-1] < arr[pivotIndex] ; arr[pivotIndex+1...high] > arr[pivotIndex]
    private static int partition2(int arr[], int low, int high) {
        // 1. 第一个元素为基准
        int e = arr[low];
        
        // 2. 两个索引
        int left = low + 1;             // arr[low+1...left) < e
        int right = high;              // arr(right, high] > e
      
        // 3. 遍历
        while (true) {
            while (left <= high && arr[left] < e) {
                left++;
            }
             
            while (right >= low + 1 && arr[right] > e) {
                right--;
            }
          
            if (left > right) {
                break;
            }
            
            swap(arr, left, right);
            left++;
            right--;
        }
      
        // 4. 交换
        swap(arr, low, right);
        
        return right;
    }
  
    public static void sort(int arr[], int low, int high) {
        if (low < high)
        {
            int pivotIndex = partition1(arr, low, high);
      
            sort(arr, low, pivotIndex - 1);
            sort(arr, pivotIndex + 1, high);
        }
    }
  
    public static void main(String[] args) {
        int arr[] = {2, 5, 8, 3, 6, 4, 9, 7, 1, 10};
        
        sort(arr, 0, arr.length - 1);
      
        for (int item : arr) {
            System.out.print(item + " ");
        }

    }
}
