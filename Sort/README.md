## Sort

* [SelectionSort](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Sort/SelectionSort)
* [InsertionSort](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Sort/InsertionSort)
* [BubbleSort](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Sort/BubbleSort)
* [ShellSort](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Sort/ShellSort)
* [MergeSort](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Sort/MergeSort)
* [QuickSort](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Sort/QuickSort)
* [HeapSort](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Sort/HeapSort)

## 排序总结

| 排序    | 平均时间复杂度    |  空间复杂度 |  稳定性 |
| --------| :-----:         | :-----:  | :-----:  |  
| 选择排序 | O(n²)    | O(1)            | 不稳定 |
| 插入排序 | O(n²)    | O(1)            | 稳定 |
| 冒泡排序 | O(n²)    | O(1)             | 稳定 |
| 希尔排序 | O(n^1.3)     | O(1)            | 不稳定 |
| 归并排序 | O(nlogn) | O(n)| 稳定 |
| 快速排序 | O(nlogn) | O(logn)          | 不稳定 |
| 堆排序   | O(nlogn) | O(1) | 不稳定 |

## Q&A

1. 如果对于不稳定的算法进行改进，如何使得不稳定的算法也稳定？
在每个输入元素加一个index，表示初始时的数组索引，当不稳定的算法排好序后，对于相同的元素对index排序即可。

2. 插入排序比较适合用于 “少量元素的数组”

3. 快速排序（不使用随机化）是否一定比插入排序快？
不一定，当输入数组已经排好序时，插入排序需要O(n)时间，而快速排序需要O(n²)时间。

4. “冒泡排序和插入排序哪个更快”呢？
插入排序的速度直接是逆序对的个数，而冒泡排序中执行“交换“的次数是逆序对的个数，因此冒泡排序执行的时间至少是逆序对的个数，因此插入排序的执行时间至少比冒泡排序快。

5. 归并排序的缺点是什么？
Out-place sort，因此相比快排，需要很多额外的空间。

6. 为什么归并排序比快速排序慢？
虽然渐近复杂度一样，但是归并排序的系数比快排大。

7. 对于归并排序有什么改进？
在数组长度为k时，用插入排序，因为插入排序适合对小数组排序。


