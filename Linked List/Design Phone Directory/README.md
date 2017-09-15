## Design Phone Directory「LeetCode 379」

题目：设计电话目录：get(提供一个没有人使用的号码)、check(检查号码是否可用)、release(删除一个号码)

```
Design a Phone Directory which supports the following operations:

get: Provide a number which is not assigned to anyone.
check: Check if a number is available or not.
release: Recycle or release a number.
Example:

// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);

// It can return any available phone number. Here we assume it returns 0.
directory.get();

// Assume it returns 1.
directory.get();

// The number 2 is available, so return true.
directory.check(2);

// It returns 2, the only number that is left.
directory.get();

// The number 2 is no longer available, so return false.
directory.check(2);

// Release number 2 back to the pool.
directory.release(2);

// Number 2 is available again, return true.
directory.check(2);
```

```cpp
class PhoneDirectory {

private:
    vector<int> recycledNums; // 保存被回收的号码
    vector<bool> flag;   // 某个号码使用状态
    int maxNum;  // 数组的大小
    int nextNum; // 索引
    int index;  // recycledNums 数组中可以被重新分配的数字的位置
    
public:
    // 初始化
    PhoneDirectory(int maxNumbers) {
        maxNum = maxNumbers;
        nextNum = 0;
        index = 0;
        flag.resize(maxNumbers, true);
        recycledNums.resize(maxNumbers);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */ 
    int get() {
        if(nextNum == maxNum && index <= 0)
            return -1;
        
        // 先看 recycledNums 里有没有数字，有的话先分配 recycledNums 里的数字
        if(index > 0)
        {
            int n = recycledNums[--index];
            flag[n] = false;
            return n;
        }
        
        // 没有的话再分配 nextNum
        flag[nextNum] = false;
        return nextNum++;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return number >= 0 && number < maxNum && flag[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if(number >= 0 && number < maxNum && !flag[number])
        {
            recycledNums[index++] = number;
            flag[number] = true;
        }
    }
};
```

参考：https://discuss.leetcode.com/topic/53136/all-c-solutions-got-lte
