说明：这是使用 Hash Table 的用户登录的实例，源代码来源于 [CS210 Lab: Hash Table](http://www.cs.uregina.ca/Links/class-info/210/Hash/#IMPLEMENTATION)

Application: Looking up Passwords

该工程使用 C++ 实现，哈希表的哈希函数采用除法散列法，解决碰撞方式采用链接法(Chaining)。

One possible use for a hash table is to store computer user login usernames and passwords.

* `hashtbl.cpp` and `hashtble.h` -- contain the implementation of the hashtable class
* `listlnk.cpp` and `listlnk.h`  -- contain the implementation of linked lists class
* `login.cpp` -- the main program. This contains the Password structure, which is inserted into the hashtable.
* `password.dat` -- contains all the users and corresponding passwords.
