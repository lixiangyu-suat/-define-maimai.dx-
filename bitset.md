初始化：`std::bitset<n> name(x); `//初始化为n位的二进制数 x 或字符串"0101....."

|**函数**|**功能**|
|---|---|
|`b.set(p)`|将第 `p` 位设为 1|
|`b.reset(p)`|将第 `p` 位设为 0|
|`b.test(p)`|返回第 `p` 位是 0 还是 1（带边界检查，更安全）|
|`b[p]`|像访问数组一样访问第 `p` 位|
|`b.count()`|统计有多少位是 1|
|`b.any()`|只要有一位是 1 就返回 true|
|`b.none()`|全部是 0 才是 true|

```c
template<size_t N>
bitset<N> fast_add(bitset<N> a, bitset<N> b) {
    while (b.any()) {
        bitset<N> carry = (a & b) << 1; // 进位
        a ^= b;                         // 无进位加法
        b = carry;                      // 将进位赋给 b 继续循环
    }
    return a;
}
```
```c
template<size_t N>
bitset<N> subtract(bitset<N> a, bitset<N> b) {
    // 补码 = 反码 + 1
    bitset<N> neg_b = fast_add(~b, bitset<N>(1));
    return fast_add(a, neg_b);
}
```
