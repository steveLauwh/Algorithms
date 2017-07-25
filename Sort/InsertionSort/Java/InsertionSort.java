package com.sort.insertionsort;

/* InsertionSort
 * 核心：通过构建有序序列，对于未排序序列，在已排序序列中从后向前扫描(对于单向链表则只能从前往后
        遍历)，找到相应位置并插入。实现上通常使用in-place排序(需用到O(1)的额外空间)
 */

public class InsertionSort {
  
    private InsertionSort() {}
  
    public static void sort(int[] arr) {
        int arrLength = arr.length;
      
        for (int i = 1; i < arrLength; i++) {
            int temp = arr[i];
          
            int j = i;
          
            while (j > 0 && arr[j - 1] > temp) {
                arr[j] = arr[j - 1];
                j--;
            }
          
            arr[j] = temp;
        }
    }
  
    public static void main(String[] args) {
        int[] arr = {6, 7, 1, 3, 2, 5, 4, 8, 9, 10};
      
        sort(arr);
      
        System.out.println("After the Insertion Sort: ");
        for (int item : arr) {
            System.out.print(item + " ");
        }
    }
}
