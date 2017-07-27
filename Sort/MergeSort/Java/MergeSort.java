//时间复杂度为 O(NlogN), 使用了等长的辅助数组，空间复杂度为 O(N)
package com.sort.mergesort;

public class MergeSort {
  
    private MergeSort() {}
  
    // 将 arr[low...middle] 和 arr[middle+1...high] 两部分进行归并
    public static void merge(int[] arr, int low, int middle, int high) {
        int[] aux = new int[high - low + 1];
        
        // 1. 复制数组
        for (int i = low; i <= high; i++) {
            aux[i - low] = arr[i];
        }
      
        // 2. 初始化两个索引 i 和 j，分别指向复制数组的上下部分起始位置
        int i = low;
        int j = middle + 1;
        
        // 3. 归并操作，索引 k 指向原待归并的数组
        for (int k = low; k <= high; k++) {
            if (i > middle) {
                arr[k] = aux[j - low];
                j++;
            } else if (j > high) {
                arr[k] = aux[i - low];
                i++;
            } else if (aux[i - low] < aux[j - low]) {
                arr[k] = aux[i - low];
                i++;
            } else {
                arr[k] = aux[j - low];
                j++;
            }
        }
    }
    
    // arr[low....high] 进行排序，
    public static void sort(int[] arr, int low, int high) {
        if (low < high) {
            int middle = low + (high - low) / 2;
        
            sort(arr, low, middle);
            sort(arr, middle + 1, high);
            merge(arr, low, middle, high);
        }
    }
  
    public static void main(String[] args) {
        int arr[] = {2, 5, 10, 4, 3, 1, 6, 8, 7, 9};
        
        sort(arr, 0, arr.length - 1);
      
        System.out.println("After the merge sort: ");
      
        for (int item : arr) {
            System.out.print(item + " ");
        }
    }
}
