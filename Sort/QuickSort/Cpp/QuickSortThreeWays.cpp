/* 三路快排：对于包含大量重复数据的数组，使用三路快排有巨大的优势
 * 对于一般性的随机数组和近乎有序的数组, 三路快排的效率虽然不是最优的, 但是是在非常可以接受的范围里
 * 三路快排是 Java 语言中默认的排序算法
 * 递归思想, partition 操作
 */

#include <iostream>
 
using namespace std;
 
template <typename T>
void quickSortThreeWays(T arr[], int low, int high)
{
    // 下面是 partition 操作
    // 1. 选取第一个元素为基准
    T e = arr[low];
 
    // 2. 初始化三个索引, 范围里不包含元素
    int left = low;        // arr[low+1...left] < v
    int right = high + 1;  // arr[right...high] > v
    int i = left + 1;      // arr[left+1...i) == v
 
    // 3. 遍历
    while (i < right)
    {
        if (arr[i] < e)
        {
            swap(arr[left+1], arr[i]);
            left++;
            i++;
        }
        else if (arr[i] > e)
        {
            swap(arr[right-1], arr[i]);
            right--;
        }
        else {   // arr[i] == v
            i++;
        }
    }
    
    /* 4. arr[low]为e, 与 arr[left] 交换, 因为此时 arr[left] < e; 
          交换后可以保持 arr[low...left-1] < e, arr[left...right-1] == e, arr[right...high] > e
     */
    swap(arr[low], arr[left]);
 
    quickSortThreeWays(arr, low, left - 1);
    quickSortThreeWays(arr, right, high); 
    
}

int main()
{
    int arr[] = {2, 5, 10, 4, 3, 1, 6, 8, 7, 9};
  
    int arrLength = sizeof(arr) / sizeof(arr[0]);
  
    quickSortThreeWays(arr, 0, arrLength - 1);
 
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
 
    cout << endl;
 
    return 0;
}
