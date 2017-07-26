package com.sort.bubblesort;

public class BubbleSort {
    
    private BubbleSort() {}
  
    public static void sort(int[] arr) {
        int arrLength = arr.length;
      
        boolean swapped = true;
      
        while (swapped) {
            swapped = false;
            
            for (int i = 1; i < arrLength; i++) {
                if (arr[i - 1] > arr[i]) {
                    swap(arr, i - 1, i);
                    swapped = true;
                }
            }
            
            arrLength--;
        }
    }
  
    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
  
    public static void main(String[] args) {
        int[] arr = {2, 5, 10, 4, 3, 1, 6, 8, 7, 9};
      
        sort(arr);
      
        for (int item : arr) {
            System.out.println(item + " ");
        }
    }
}
