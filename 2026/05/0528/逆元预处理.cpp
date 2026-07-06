#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9+7;

ll fact[500005], invFact[500005];

ll power(ll a, ll b) {
    ll res = 1;
    for (a %= MOD; b; b >>= 1, a = a * a % MOD) //快速幂，a为底，res为目标数; O(log MOD)
        if (b & 1) res = res * a % MOD;
    return res;
}

void initfactory(int N) {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;
    invFact[N] = power(fact[N], MOD - 2); 
    // 阶乘逆元的递推公式：inv(n!) = inv((n+1)!) * (n+1)
    for (int i = N - 1; i >= 0; i--) invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    //这里的invfact[1]都可能是一个很大的数，所有全程使用ll
}