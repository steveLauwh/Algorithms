/* Quick Sort: 比 Merge Sort 快
 * 时间复杂度：O(nlogn)
 * 额外空间：O(logn)
 * in-place
 * 非稳定排序
 * 递归思想
 * 核心：如何 partition 操作， 写 partition 功能，先画图分析好，再写代码
 * 归并排序和快速排序中，当小规模的数组时，使用插入排序优化
 */
#include <iostream>

using namespace std;

/* partition1：一个索引移动 
   对 arr[low...high] 进行 partition 操作;
   返回索引 pivotIndex, 使得arr[low...pivotIndex-1] < arr[pivotIndex] ; arr[pivotIndex+1...high] > arr[pivotIndex]
*/
template <typename T>
int partition1(T arr[], int low, int high)
{
    // 1. 选取第一个元素为基准(注：可随机选取一个元素与第一个元素交换)
    T e = arr[low];
    
    // 2. 初始化基准索引
    int pivotIndex = low;
  
    // 3. arr[low+1...pivotIndex] < e , arr[pivotIndex+1...i) > e , 其中 i 向后遍历索引
    for (int i = low + 1; i <= high; i++)
    {
        // 当要排序的元素小于基准，先将基准索引向后移一位，再交换
        // 当
        if (arr[i] < e)
        {
            pivotIndex++;
            swap(arr[pivotIndex], arr[i]);
        }       
    }
    
    // 4. 第一个元素为基准值与最新基准索引指向的值进行互换
    swap(arr[low], arr[pivotIndex]);
    
    return pivotIndex;
}

/* partition2：双路快排, 步骤与 partition1 一样，只不过是两个索引碰撞 */
template <typename T>
int partition2(T arr[], int low, int high)
{
    // 1. 选取第一个元素为基准(注：可随机选取一个元素与第一个元素交换)
    T e = arr[low];
  
    // 2. 两路指针，i 指向 low+1，j 指向 high
    // arr[low+1...i) <= e; arr(j...high] >= e
    int i = low + 1;
    int j = high;
  
    while (i <= j)
    {
        while (i <= high && arr[i] < e)
        {
            i++;
        }
        while (j >= low + 1 && arr[j] > e)
        {
            j--;
        }
        
        if (i < j)  // 注意: i 和 j 在做递增和递减
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
  
    // 这里为什么跟 arr[j] 交换，因为此时arr[j]是小于e
    swap(arr[low], arr[j]);
    
    return j;
}

// 对 arr[low....high] 快排
template <typename T>
void quickSort(T arr[], int low, int high)
{
    if (low < high)   // 加此条件，为了递归导致死循环
    {
        // 1. partition 操作，求出基准 pivot 位置的索引
        int pivotIndex = partition2(arr, low, high);
      
        // 2. 以基准 pivot 为边界，左边快排
        quickSort(arr, low, pivotIndex-1);
        
        // 3. 以基准 pivot 为边界，右边快排
        quickSort(arr, pivotIndex+1, high);
    }
}

int main()
{
    int arr[] = {2, 5, 10, 4, 3, 1, 6, 8, 7, 9};
  
    int arrLength = sizeof(arr) / sizeof(arr[0]);
  
    quickSort(arr, 0, arrLength - 1);
  
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
  
    cout << endl;
  
    return 0;
}
