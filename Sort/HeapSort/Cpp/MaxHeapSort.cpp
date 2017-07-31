#include <iostream>
#include "MaxHeap.h"
#include <ctime>
#include <cmath>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 堆排序：堆排序其实真正重点在于如何建堆, 如何取出最大或最小元素, 实现 ShiftDown 和 ShiftUp 操作。
// heapSort1：将所有的元素依次添加到堆中(插入), , , 然后依次从堆中取出(extractMax), , , , 就完成堆排序。
// heapSort2：利用 heapify 过程创建堆, 然后依次从堆中取出(extractMax), , , , , 就完成排序。
// heapSort1 和 heapSort2 比较：
//                        heapSort1 无论是创建堆的过程, 还是从堆中依次取出元素的过程, 时间复杂度均为 O(nlogn)
//                        heapSort2 创建堆的过程时间复杂度为O(n), 将所有元素依次从堆中取出来, 时间复杂度为 O(nlogn)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void heapSort1(T arr[], int n)
{
    MaxHeap<T> maxHeap = MaxHeap<T>(n);
    
    for (int i = 0; i < n; i++)
    {
        maxHeap.insert(arr[i]);   // 创建堆，实际利用 ShiftUp 操作
    }
  
    for (int i = n-1; i >= 0; i--)
    {
        arr[i] = maxHeap.extractMax();  // 取最大元素存储, 实际利用 Shift Down 操作
    }
}

template <typename T>
void heapSort2(T arr[], int n)
{
    MaxHeap<T> maxHeap = MaxHeap<T>(arr, n);  // heapify 过程创建堆, 实际利用 Shift Down 操作
    
    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] = maxHeap.extractMax();       // 取最大元素存储, 实际利用 Shift Down 操作
    }
}

int main()
{
    srand(time(NULL));
    int arr[] = {2, 5, 10, 9, 16, 19, 42, 37, 3, 1};
    
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    
    if (rand() % 2 == 0)
    {
        cout << "heapSort1: " << " ";
        heapSort1(arr, arrLength);
    }
    else
    {
        heapSort2(arr, arrLength);
    }
    
  
    for (int i = 0; i <arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
  
    return 0;
}
