/* Shell Sort: 插入排序的扩展，将待排序的数组按照步长 gap 进行分组，然后将每组的元素利用插入排序的方法进行排序，直到 gap 为 1，利用插入完成排序。
 */

#include <iostream>

using namespace std;

template <typename T>
void shellsort(T arr[], int n)
{
    int gap = 1;
    
    while (gap < n / 3)
    {
        gap = gap * 3 + 1;  // 步长 gap
    }
  
    while (gap >= 1)
    {
        for (int i = gap; i < n; i++)
        {
            T temp = arr[i];
            
            int j = i;
          
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j = j - gap;
            }
          
            arr[j] = temp;
        }
        
        gap = gap / 3;
    }
}

int main()
{
    int arr[] = {2, 5, 10, 4, 3, 1, 6, 8, 7, 9};
    
    int arrLength = sizeof(arr) / sizeof(arr[0]);
  
    shellsort(arr, arrLength);
  
    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
  
    return 0;
}
