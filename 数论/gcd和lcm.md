
[Problem - 2210C1 - Codeforces](https://codeforces.com/problemset/problem/2210/C1) 的知识点

- $\gcd(a, b, c) = \gcd(\gcd(a, b), c)$

- 如果一个数 $x$ 既是 $A$ 的倍数，又是 $B$ 的倍数，那么 $x$ 一定是 $\text{lcm}(A, B)$ 的倍数。

- **$\gcd(1, a) = 1$**：$1$ 与任何正整数的最大公约数都是 $1$。
- **$\gcd(0, a) = a$**：因为任何正整数 $a$ 都能整除 $0$ ($0 \div a = 0$)，且能整除 $a$ 的最大数就是 $a$ 自身。
- **$\gcd(a, a) = a$**。

- **$\text{lcm}(1, a) = a$**：$1$ 是任何整数的约数，所以它们的最小公倍数就是 $a$。
- **$\text{lcm}(0, a) = 0$**：从定义上讲，能被 $0$ 整除的数只有 $0$。但在某些题目背景（比如本题的分母位置）下，$0$ 可能代表无穷大或非法，需要特殊处理。
- **$\text{lcm}(a, b) = \frac{|a \cdot b|}{\gcd(a, b)}$**：这是最常用的转换公式。
- 建议自定义lcm，防止爆掉
```c
// 自定义安全的 LCM，先除后乘 
ll lcm(ll a, ll b) { 
	if (a == 0 || b == 0) return 0; // __gcd 是内置函数，速度极快 
	return (a / __gcd(a, b)) * b; 
}
```