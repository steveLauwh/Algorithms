#include <iostream>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

/* 迭代实现
 * 二分查找法：找到 target, 返回相应的索引 index; 没找到, 返回 -1.
 * 在  arr[low...high] 中查找 target 
 */
template <typename T>
int binarySearch_Iteration(T arr[], int n, int target)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
	int mid = low + (high - low) / 2;

	if (arr[mid] == target)
	{
	    return mid;
	}

	// [mid+1...high]
	if (arr[mid] < target)
	{
	    low = mid + 1;
	}
	else // [low...mid-1]
	{
	    high = mid - 1;
	}
    }

    return -1;
}

/* 递归实现二分查找法
 */
template <typename T>
int binarySearch_Recursive(T arr[], int low, int high, int target)
{
    if (low > high)
    {
	return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
    {
	return mid;
    }
    else if (arr[mid] < target)
    {
	return binarySearch_Recursive(arr, mid + 1, high, target);
    }
    else
    {
        return binarySearch_Recursive(arr, low, mid - 1, target);
    }
}

int main()
{
    srand(time(NULL));

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int arrLength = sizeof(arr) / sizeof(arr[0]);

    if (rand() % 2 == 0)
    {
        cout << "Binary Search Iteration: " << " ";
        int v = binarySearch_Iteration(arr, arrLength, 19);

	cout << v << endl;
    }
    else
    {
	cout << "Binary Search Recursive: " << " ";
	int w = binarySearch_Recursive(arr, 0, arrLength - 1, 19);

	cout << w << endl;
    }

    return 0;
}

