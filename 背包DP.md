特征1：dp依赖于前n-1个值中某几个值，因此不能像斐波那契数列一样把O(N)->O(2);

# Codeforces 148E - Porcelain
#### 原文 (Original Text)

> Polycarpus has $n$ shelves with porcelain items. On each shelf, items are arranged in a row.
> 
> Polycarpus can take items from the shelves, but there is a rule: he can only take an item from a shelf if it is either the leftmost or the rightmost item on that shelf.
> 
> He wants to take exactly $m$ items in total to maximize the sum of their values.
> 
> **Input:**
> 
> The first line contains $n$ and $m$ ($1 \le n, m \le 100$).
> 
> Each of the next $n$ lines starts with $k_i$ (number of items on the $i$-th shelf), followed by $k_i$ integers (values of items).
> 
> **Output:**
> 
> The maximum total value.

#### 2. 直译 (Direct Translation)

> Polycarpus 有 $n$ 排架子，上面摆放着瓷器。在每个架子上，瓷器排成一列。
> 
> Polycarpus 可以从架子上取走瓷器，但有一个规则：他只能取走某排架子最左端或最右端的瓷器。
> 
> 他总共想要取走 **恰好 $m$ 个** 瓷器，目标是使这些瓷器的价值总和最大。
> 
> **输入：**
> 
> 第一行包含 $n$（架子数）和 $m$（总共要取的数量）。
> 
> 接下来的 $n$ 行，每行开头是 $k_i$（该架子上的瓷器数），后面跟着 $k_i$ 个整数代表每个瓷器的价值。
> 
> **输出：**
> 
> 最大价值总和。