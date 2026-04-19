```c
#include <iostream>
#include <set>

void demo() {
    std::multiset<int> s = {10, 20, 20, 30, 40};

    // 查找第一个 >= 20 的元素
    auto it = s.lower_bound(20); 
    if (it != s.end()) {
        std::cout << "找到: " << *it << std::endl; // 输出 20
    }
    // 查找第一个 > 20 的元素
    auto it = s.upper_bound(20); 
    if (it != s.end()) {
        std::cout << "找到: " << *it << std::endl; // 输出 20
    }
    
    it-- : 查找最后一个<20的元素
}
```
