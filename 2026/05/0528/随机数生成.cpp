#include <bits/stdc++.h>
using namespace std;

int get_rand(int min, int max) {
    //或：static mt19937 rng(0);，每次运行不放心可以换成1,2,......0x3f3f3f3f
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // 尽管 dist 还是局部变量，但这是 C++ 标准库推荐的、兼顾安全与速度的写法
    return uniform_int_distribution<int>(min, max)(rng);
}
//static:等价于global，不会重复初始化和函数结束后的delete