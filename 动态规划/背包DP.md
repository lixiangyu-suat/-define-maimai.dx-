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




# 单调队列优化
- 前提：==物品数量很大（>10^3, log(10^3) = 10)，物品体积很小==；否则，二进制拆分足够
- Key:外层物品 i : 1--n
	- 中间余数（轨道）y : 1--`V[i]` 
		- `dq.clear()`
		- 内层：x : 1 -- `x0`, `x0 * V[i] + y <= C` 
			- 更新`dp_now[x * V[i] + y] = ....`
			- //==倍数x==可能很大（最大为背包容量C / w[i])，但是每种物品可能就两三个，因此等价于在某一个背包容量附近找合适的情况（选1-d[i]个物品为最优），==余数y负责调和，保证连续==，每一个连续的整数都能被遍历到。
---

- 我们不使用deque来维护一个双端队列，最好使用静态数组模拟；
- 
  ```c
	  int q[MAXV], head, tail;
	// 清空队列：
	head = 1, tail = 0;
	// push_back()
	q[++tail] = x; 
	// pop_front()
	head++;
	// pop_back()
	tail--;
  ```
物品体积大，最内层循环效率可能由于缓存命中率而降低；
- 当 $w_i$ 小时，你访问 `dp[j], dp[j+w_i], dp[j+2w_i]`，这些点距离很近，很可能都在同一个缓存行里，速度飞快。
    
- 当 $w_i$ 很大时（比如 $w_i = 5000$），你访问完 `dp[1]`，下一个点就要跳到 `dp[5001]`。CPU 必须重新去内存里拉取数据，这种 **Cache Miss** 会导致明显的性能下降。
