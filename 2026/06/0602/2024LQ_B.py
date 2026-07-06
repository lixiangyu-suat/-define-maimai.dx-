# C 是题目中的常数
C = 10120300500
# 我们需要分解的是 2 * C
total_prod = 2 * C

ans_sum = 0
valid_n = set()  # 用集合去重，防止重复计算

# 遍历较小的因数 k
for k in range(1, int(total_prod**0.5) + 1):
    if total_prod % k == 0:
        k2 = total_prod // k  # 另一个对应的因数
        
        # 必须满足两者都是偶数
        if k % 2 == 0 and k2 % 2 == 0:
            # x + y = k2, x - y = k
            x = (k2 + k) // 2
            n = x * x - C
            valid_n.add(n)

print(sum(valid_n))