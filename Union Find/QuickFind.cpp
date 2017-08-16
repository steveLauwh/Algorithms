#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdlib>

using namespace std;

#define N 100

class UnionFind {
private:
    int *arr;  // 本身就是一个数组
    int count;
    
public:
    UnionFind(int n)
    {
        arr = new int[n];
        
        for (int i = 0; i < n; i++)
        {
            arr[i] = i;
        }
        
        count = n;
    }
    
    ~UnionFind()
    {
        delete[] arr;
    }
    
    // 查找操作
    int find(int i)
    {
        assert(i >= 0 && i < count);
        return arr[i];
    }
    
    // 查看元素 p 和 元素 q 是否连接, 当 arr[p] == arr[q], 表示连接
    bool isConnected(int p, int q)
    {
        return find(p) == find(q);
    }
    
    // 合并元素 p 和 元素 q
    void unions(int p, int q)
    {
        int pID = find(p);
        int qID = find(q);
        
        if (pID == qID)
            return;
        
        // O(n), 遍历, 当 将所有等于 arr[p]，赋值等于 arr[q]
        for (int i = 0; i < count; i++)
        {
            if (arr[i] == pID)
            {
                arr[i] = qID;
            }
        }       
    }    
};

int main()
{
    srand(time(NULL));
   
    UnionFind uf = UnionFind(N);
    
    for (int i = 0; i < N; i++)
    {
        int a = rand() % N;
        int b = rand() % N;
        
        cout << uf.isConnected(a, b) << " ";  // 随机选择两个元素，看是否连接
    }
    
    for (int i = 0; i < N; i++)
    {
        int a = rand() % N;
        int b = rand() % N;
        
        uf.unions(a, b);  // 随机选择两个元素，合并
    }  
}
