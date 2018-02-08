# 位操作

* [Sum of Two Integers](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Bit%20Manipulation/SumOfTwoIntegers)
* [Single Number](https://github.com/steveLauwh/Data-Structures-And-Algorithms/tree/master/Bit%20Manipulation/Single%20Number)

## 位操作的基础

1.测试某位是否为 1， 为 1 返回 true(1)，否则 false(0)

```c++
// 测试 a 的第 b 位是否为 1
#define TSTBIT(a, b)  (((a) & (1 << b)) ? (true) : (false))
```

2.将某位置为 1

```c++
// 将 a 的第 b 位置为 1
#define SETBIT(a, b)  (a = ((a) | (1 << b)))
```

3.将某位置为 0

```c++
// 将 a 的第 b 位置为 0
#define CLRBIT(a, b)  (a = ((a) & (~(1 << (b)))))
```

```c++
// 测试
#include <iostream>

#define TSTBIT(a, b)  (((a) & (1 << b)) ? (true) : (false))
#define SETBIT(a, b)  (a = ((a) | (1 << b)))
#define CLRBIT(a, b)  (a = ((a) & (~(1 << (b)))))

int main()
{
    int number = 10; 

    std::cout << TSTBIT(number, 2) << std::endl;  // 0

    std::cout << SETBIT(number, 3) << std::endl;  // 10

    std::cout << CLRBIT(number, 3) << std::endl;  // 2

    return 0;
}
```
