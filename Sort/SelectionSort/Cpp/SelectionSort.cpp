#include <iostream>

using namespace std;

// an in-place comparison sort，O(N^2)，不适合大数据量
template <typename T>
void selectionSort(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int index = i;
        
        // 从待排序中，找到元素值最小的索引
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[index])
            {
                index = j;
            }
        }
      
        // 将待排序的第一个元素与待排序中最小元素进行交换
        swap(arr[index], arr[i]);
    }
}

int main()
{
    int arr[] = {2, 5, 10, 4, 3, 1, 6, 8, 7, 9};
    
    int arrLength = sizeof(arr) / sizeof(arr[0]);
  
    selectionSort(arr, arrLength);
  
    for (int i = 0; i < arrLength; i++) 
    {
        cout << arr[i] << " ";
    }
  
    cout << endl;
}
