/* Merge Sort: 一层层向下递归，每次二分，然后从最底层开始向上一层层归并。
 * 时间复杂度 O(nlogn)
 * 空间复杂度 O(n)
 * 适合处理大数量级的数据
 * 递归思想
 * 归并过程：对上下两个已排序的数组进行合并，首先申请一个一样的数组临时空间，两个索引分别指向上和下的首位置，进行比较，放入原数组中。
*/
#include <iostream>

using namespace std;

// 将 arr[low...middle] 和 arr[middle+1...high] 两部分进行归并
template <typename T>
void merge(T arr[], int low, int middle, int high)
{
    // 1. 将待合并的两部分排好序的数组复制一份
    T* aux = new T[high - low + 1];
  
    for (int i = low; i <= high; i++)
    {
        aux[i - low] = arr[i];
    }
  
    // 2. 初始化两个索引 i 和 j，分别指向复制数组的上下部分起始位置
    int i = low;
    int j = middle + 1;
    
    // 3. 归并操作，索引 k 指向原待归并的数组
    for (int k = low; k <= high; k++)
    {
        // 当左部分处理完
        if (i > middle)
        {
            arr[k] = aux[j - low];
            j++;
        }
        else if (j > high)    // 当右部分处理完
        {
            arr[k] = aux[i - low];
            i++;
        }
        else if (aux[i - low] < aux[j - low])   // 当左部分所指向的元素小于右部分所指向的元素
        {
            arr[k] = aux[i - low];
            i++;
        }
        else
        {   // 当左部分所指向的元素小于右部分所指向的元素
            arr[k] = aux[j - low];                      
            j++;
        }
    }
    
    delete[] aux;
}


// 归并排序采用递归思想, 对arr[low...high]的范围进行排序
template <typename T>
void mergeSort(T arr[], int low, int high)
{
    if (low >= high)  // 条件判断很重要，否则死循环
        return;
    
    int middle = low + (high - low) / 2;
  
    // 左部分排序
    mergeSort(arr, low, middle);
  
    // 右部分排序
    mergeSort(arr, middle + 1, high);
  
    // 左右合并
    merge(arr, low, middle, high);
}

int main()
{
    int arr[] = {2, 5, 10, 4, 3, 1, 6, 8, 7, 9};
  
    int arrLength = sizeof(arr) / sizeof(arr[0]);
  
    mergeSort(arr, 0, arrLength - 1);
  
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
  
    cout << endl;
}

