#ifndef __MAXHEAP_H_
#define __MAXHEAP_H_
#include <iostream>
#include <cassert>

using namespace std;

template <typename Item>
class MaxHeap
{
private:
    Item *data;      // 以数组方式存储最大堆
    int capacity;   // 容量
    int count;     // 节点个数
  
private:
    // parent[i/2], 比较子节点与父节点，子节点大于父节点，则交换
    void shiftUp(int i)
    {
        while (i > 1 && data[i/2] < data[i])
        {
            swap(data[i/2], data[i]);
            i /= 2;
        }
    }
  
    // Shift Down，父亲节点与子节点比较
    void shiftDown(int i)
    {
       while (2*i <= count)
       {
            int j = 2*i;
            if (j + 1 <= count && data[j+1] > data[j])
            {
                j++;   // 子节点最大的索引
            }
            
            if (data[i] > data[j])
                break;
         
            swap(data[i], data[j]);  // 父节点与最大子节点交换
            
            i = j;
       }
    }
  
public:
    MaxHeap(int capacity)
    {
        data = new Item[cpacity + 1];
        this->capacity = capacity;
        count = 0;
    }
  
    // 数组建堆 heapify， 时间复杂度O(n)
    // 只有一个节点的树就是堆，而在完全二叉树中，所有序号 i > [n/2] 的节点都是叶子，因此以这些节点为根的子树均是堆。
    // 这样，只需要依次将以序号为[n/2]、[n/2]-1,...1的节点作为根的子树都调整为堆即可。
    MaxHeap(Item arr[], int n)
    {
        data = new Item[n+1];
        capacity = n;
        
        for (int i = 0; i < n; i++)
        {
            data[i+1] = arr[i];  // 此MaxHeap是从data[1]开始存储节点
        }
        
        count = n;
        
        // 对所有非叶子节点做调整
        for (int i = count/2; i >= 1; i--)
        {
            shiftDown(i);
        }
    }
  
    ~MaxHeap()
    {
        delete[] data;
    }
  
    int size()
    {
        return count;
    }
    
    bool isEmpty()
    {
        return count == 0;
    }
    
    // 插入元素到最大堆中, 做 Shift Up 操作保持最大堆
    void insert(Item item)
    {
        assert(count + 1 <= capacity);
        data[count+1] = item;  // 第一个元素存储在data[1]
        count++;
        shiftUp(count);       // 向上 Shift Up
    }
  
    // 从最大堆中取出堆顶元素
    Item extractMax()
    {
        assert(cout > 0);
        Item ret = data[1];  //堆顶元素
      
        swap(data[1], data[count]);  // 将堆顶元素与最后一个元素交换后，做 Shift Down 操作
        
        count--;
        
        shiftDown(1);
      
        return ret;
    }

public:
    void printMaxHeap()
    {
        if (typeid(Item) != typeid(int))
        {
            cout << "The print function used int type!" << endl;
            return;
        }
           
        for (int i = 1; i <= size(); i++)
        {
            cout << data[i] << " ";
        }
        
        cout << endl;
    }
};

#endif
