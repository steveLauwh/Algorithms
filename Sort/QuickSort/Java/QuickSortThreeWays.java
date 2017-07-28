package com.sort.quicksortthreeways;

public class QuickSortThreeWays {
    private QuickSortThreeWays() {}
    
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
      
        arr[i] = arr[j];
      
        arr[j] = temp;
    }
  
    public static void sort(int[] arr, int low, int high) {
        if (low < high) {
            
           // partition 操作
            int e = arr[low];
            
            int left = low;        // arr[low+1...left] < e
            int right = high + 1;  // arr[right...high] > e
            int i = low + 1;       // arr[left+1...i) == e
          
            while (i < right) {
                if (arr[i] < e) {
                    swap(arr, i, left + 1);
                    i++;
                    left++;
                } else if (arr[i] > e) {
                    swap(arr, i, right - 1);
                    right--;
                } else {
                    i++;
                }
            }
          
            swap(arr, low, left);
            
            // arr[low...left-1] < e 排序
            sort(arr, low, left - 1);
            
            // arr[right...high] > e 排序
            sort(arr, right, high);
        }
    }
    
    public static void main(String[] args) {
        int[] arr = {2, 5, 8, 7, 6, 4, 13, 7, 1, 11};
        
        sort(arr, 0, arr.length - 1);
        
        for (int item : arr) {
            System.out.print(item + " ");
        }
    }
}
