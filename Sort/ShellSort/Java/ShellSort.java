/* Shell Sort
 * 核心: 基于插入排序，使数组中任意间隔为h的元素都是有序的，即将全部元素分为h个区域使用插入排
         序。其实现可类似于插入排序但使用不同增量。更高效的原因是它权衡了子数组的规模和有序性。
 */

package com.sort.shellsort;

public class ShellSort {
    private ShellSort() {}
  
    public static void sort(int[] arr) {
        int gap = 1;
      
        int arrLength = arr.length;
      
        while (gap < arrLength / 3) {
            gap = gap * 3 + 1;
        }
      
        while (gap >= 1) {
          
            for (int i = gap; i < arrLength; i++) {
              
                int temp = arr[i];
                int j = i;
              
                while (j >= gap && arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    j = j - gap;
                }
                
                arr[j] = temp;
            }
            
            gap = gap / 3;
        }
    }
  
    public static void main(String[] args) {
        int[] arr = {2, 5, 10, 4, 3, 1, 6, 8, 7, 9};
        
        sort(arr);
        
        System.out.println("After the shell sort : ");
      
        for (int item : arr) {
            System.out.print(item + " ");
        }
    }
}


