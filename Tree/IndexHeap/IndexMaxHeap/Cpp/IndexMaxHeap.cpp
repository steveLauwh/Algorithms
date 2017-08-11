#include <iostream>
#include <cassert>

using namespace std;

// 最大索引堆：在普通堆的基础上，开辟一个存放索引的数组。
template <typename T>
class IndexMaxHeap
{
private:
    T *data;        // 存放最大索引堆的数据
    int *index;     // 存放最大索引堆的索引
    int capacity;   // 容量
    int count;      // 索引堆的元素个数
  
    // 索引堆中, 数据之间的比较根据 data 的大小进行比较, 但实际操作的是索引
    void shiftUp(int i)
    {
        while (i > 1 && data[index[i/2]] < data[index[i]])
        {
            swap(index[i/2], index[i]);
            i /= 2;
        }
    }
  
    void shiftDown(int i)
    {
        while (2 * i <= count)
        {
            int j = 2 * i;
            
            if (j + 1 <= count && data[index[j]] < data[index[j+1]])
            {
                j++;
            }
            
            if (data[index[i]] >= data[index[j]])
                break;
          
            swap(data[index[i]], data[index[j]]);
            
            i = j;
        }
    }
     
  
public:
    IndexMaxHeap(int capacity)
    {
        data = new T[capacity + 1];
        index = new int[capacity + 1];
        count = 0;
        this->capacity = capacity;
    }
  
    ~IndexMaxHeap()
    {
        delete[] data;
        delete[] index;
    }
  
    int size()
    {
        return count;
    }
  
    // 判断索引堆是否为空
    bool isEmpty()
    {
        return count == 0;
    }
  
    // 插入元素，向最大索引堆插入一个新的元素，元素的索引为 i， 元素为 item
    // 对于用户来说，索引是从 0 开始
    void insert(int i, T item)
    {
        assert(count + 1 <= capacity);
        assert(i + 1 >= 1 && i + 1 <= capacity);
      
        i = i + 1;
        data[i] = item;
        count++;
        index[count] = i; // 向存储索引的数组尾端插入索引
      
        shiftUp(count);  // 调整存储索引的堆
    }
  
    // 从最大堆中取出最大元素，即为存放索引的堆的堆顶索引，所对应的元素
    T extractMax()
    {
        assert(count > 0);
      
        T ret = data[index[1]]; // 最大元素
        // 调整存储索引的堆
        swap(index[1], index[count]);
        count--;
        shiftDown(1); // 调整存储索引的堆
      
        return ret;
    }
  
    // 从最大堆中取出存放索引的堆的堆顶索引
    int extractMaxIndex()
    {
        assert(count > 0);
        
        int ret = index[1] - 1; // 用户，从索引 0 开始
        swap(index[1], index[count]);
        count--;
        shiftDown(1);
      
        return ret;
    }
    
    // 从索引堆中取出最大元素
    T getMax()
    {
        assert(count > 0);
        
        return data[index[1]];
    }
  
    // 从索引堆中取出最大元素对应的索引
    int getMaxIndex()
    {
        assertt(count > 0);
        
        return index[1] - 1;
    }
     
    // 获取最大索引堆中索引为i的元素
    T getItem(int i)
    {
        assert(i + 1 >= 1 && i + 1 <= capacity);
        
        return data[i+1];
    }
  
    // 将最大索引堆中索引为 i 的元素修改为 newItem
    void change(int i, T newItem)
    {
        i += 1;
        data[i] = newItem;
        
        // 找到indexes[j] = i, j表示data[i]在堆中的位置
        // 之后shiftUp(j), 再shiftDown(j)
        for (int j = 1; j <= count; j++)
        {
            if (index[j] == i)
            {
                shiftUp(j);
                shiftDown(j);
                
                return;
            }
        }
    }
};

template <typename T>
void heapSort(T arr[], int n)
{
    IndexMaxHeap<T> indexMaxHeap = IndexMaxHeap<T>(n);
    
    for (int i = 0; i < n; i++)
    {
        indexMaxHeap.insert(i, arr[i]);
    }
  
    indexMaxHeap.change(5, 88);
  
    for (int i = n - 1; i >= 0; i--)
    {
        arr[i] = indexMaxHeap.extractMax();
    }
}

int main()
{
    int arr[] = {100, 18, 9, 9, 53, 63, 42, 37, 3, 1};
    int arrLength = sizeof(arr) / sizeof(arr[0]);
  
    heapSort(arr, arrLength);
  
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
  
    return 0;
}
