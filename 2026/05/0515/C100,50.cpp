#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 500005, M = 1e9+7;
ll fact[N], invfact[N];

ll power(ll a, ll n){//这里参数等也要传很多 ll
    ll ans = 1;
    while (n){
        if (n&1) ans = ans * a % M; //乘以底数a
        a = a * a % M; //底数自乘
        n >>= 1;
    }
    return ans;
}

void initfact(int n){
    fact[0] = 1;
    for (int i = 1; i <= n; i++){
        fact[i] = fact[i-1] * i % M;
    }
    invfact[n] = power(fact[n], M-2);
    for (int i = n-1; i >= 0; i--){
        invfact[i] = invfact[i+1] * (i+1) % M;
    }
}

int main(){
    initfact(500000); //记得声明初始化
    cout << fact[1] << ' ' << invfact[1] << endl;
    while (true){
        int a, b;
        cin >> a >> b;
        if (a < b) {
            cout << "a < b!!!" << endl;
            continue;
        }
        ll ans = 1;
        ans = ans * fact[a] % M;
        ans = ans * invfact[b] % M;
        ans = ans * invfact[a-b] % M;
        printf("C(%d, %d) = %d\n", a, b, ans);
    }
    return 0;
}