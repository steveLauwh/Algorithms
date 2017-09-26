# ifndef __INDEXMINHEAP_H_
# define __INDEXMINHEAP_H_

#include <iostream>
#include <cassert>

using namespace std;

// 最小索引堆：在普通堆的基础上，开辟一个存放索引的数组。
template <typename T>
class IndexMinHeap
{
private:
    T *data;        // 存放最小索引堆的数据
    int *index;     // 存放最小索引堆的索引
    int capacity;   // 容量
    int count;      // 索引堆的元素个数
  
    // 索引堆中, 数据之间的比较根据 data 的大小进行比较, 但实际操作的是索引
    void shiftUp(int i)
    {
        while (i > 1 && data[index[i/2]] > data[index[i]])
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
            
            if (j + 1 <= count && data[index[j]] > data[index[j+1]])
            {
                j++;
            }
            
            if (data[index[i]] < data[index[j]])
                break;
          
            swap(data[index[i]], data[index[j]]);
            
            i = j;
        }
    }
     
  
public:
    IndexMinHeap(int capacity)
    {
        data = new T[capacity + 1];
        index = new int[capacity + 1];
        count = 0;
        this->capacity = capacity;
    }
  
    ~IndexMinHeap()
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
  
    // 插入元素，向最小索引堆插入一个新的元素，元素的索引为 i， 元素为 item
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
  
    // 从最小堆中取出最小元素，即为存放索引的堆的堆顶索引，所对应的元素
    T extractMin()
    {
        assert(count > 0);
      
        T ret = data[index[1]]; // 最小元素
        // 调整存储索引的堆
        swap(index[1], index[count]);
        count--;
        shiftDown(1); // 调整存储索引的堆
      
        return ret;
    }
  
    // 从最小堆中取出存放索引的堆的堆顶索引
    int extractMinIndex()
    {
        assert(count > 0);
        
        int ret = index[1] - 1; // 用户，从索引 0 开始
        swap(index[1], index[count]);
        count--;
        shiftDown(1);
      
        return ret;
    }
    
    // 从索引堆中取出最小元素
    T getMin()
    {
        assert(count > 0);
        
        return data[index[1]];
    }
  
    // 从索引堆中取出最小元素对应的索引
    int getMinIndex()
    {
        assert(count > 0);
        
        return index[1] - 1;
    }
     
    // 获取最小索引堆中索引为i的元素
    T getItem(int i)
    {
        assert(i + 1 >= 1 && i + 1 <= capacity);
        
        return data[i+1];
    }
  
    // 将最小索引堆中索引为 i 的元素修改为 newItem
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

#endif
