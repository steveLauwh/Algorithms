/* Bubble Sort: 下沉式冒泡，时间平均复杂度 O(N^2)，空间复杂度 O(1)，可以使用在已接近有序的数组情况下 */

#include <iostream>

using namespace std;

template <typename T>
void bubbleSort(T arr[], int n)
{
    bool swapped = true;
  
    while (swapped)
    {
        swapped = false;  // 交换标志
        
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
        }
    }
}

template <typename T>
void bubbleSort2(T arr[], int n)
{
    bool swapped = true;
    
    while (swapped)
    {
        swapped = false;
        
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
        
        n--;  // 每优化一趟，最大的元素放在最后的位置，所以最后元素不用在排序
    }
}

int main()
{
    int arr[] = {2, 5, 10, 4, 3, 1, 6, 8, 7, 9};
  
    int arrLength = sizeof(arr) / sizeof(arr[0]);
  
    bubbleSort2(arr, arrLength);
  
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
}
