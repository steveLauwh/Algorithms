/* SelectionSort 
 * 核心：不断地选择剩余元素中的最小者。
   1. 找到数组中最小元素并将其和数组第一个元素交换位置。
   2. 在剩下的元素中找到最小元素并将其与数组第二个元素交换，直到整个数组排序。
 */

package com.sort.selectionsort;

public class SelectionSort {

  private SelectionSort() {}
   
  public static void sort(int[] arr) {
      int arrLength = arr.length;
      
      for (int i = 0; i < arrLength; i++) {
          int index = i;
        
          for (int j = i+1; j < arrLength; j++) {
              if (arr[j] < arr[index]) {
                  index = j;
              }
          }
        
          swap(arr, i, index);
      }
  }
  
  public static void swap(int[] arr, int i, int j) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
  }
  
  public static void main(String[] args) {
      int[] arr = {6, 7, 1, 3, 2, 5, 4, 8, 9, 10};
      
      sort(arr);
    
      System.out.println("After the Selection Sort: ");
      for (int item : arr) {
          System.out.print(item + " ");
      }
  }
}
