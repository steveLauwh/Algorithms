#include <iostream>

using namespace std;

// 插入排序，时间复杂度O(N^2)，需用到O(1)的额外空间，在小数据量和已接近排序的数据量情况下，使用插入排序比较高效
template <typename T>
void insertionSort(T arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // 待排序的元素
        T temp = arr[i];
        
        // j 最后保存元素 temp 应该插入的位置
        int j = i;
      
        while (j > 0 && arr[j - 1] > temp)
        {
            arr[j] = arr[j - 1];
            j--;
        }
      
        arr[j] = temp;
    }
}

int main()
{
    int arr[] = {2, 5, 10, 4, 3, 1, 6, 8, 7, 9};
    
    int arrLength = sizeof(arr) / sizeof(arr[0]);
  
    insertionSort(arr, arrLength);
  
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
  
    cout << endl;
}
