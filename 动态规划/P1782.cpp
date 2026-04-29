/*
https://www.luogu.com.cn/problem/P1782
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> item(2, vector<int>(10005));//泛化物品
vector<int> v(10005+1), w(10005+1), d(10005+1);

void SinglePack(vector<int>& dp, int C, int vi, int wi){
    for (int i = C; i >= vi; i--){
        dp[i] = max(dp[i-vi]+wi, dp[i]);
    }
}
void CompletePack(vector<int>& dp, int C, int vi, int wi){
    for (int i = vi; i <= C; i++){
        dp[i] = max(dp[i-vi]+wi, dp[i]);
    }
}
void MultiplePack(vector<int>& dp, int C, int u){
    if (d[u] >= C/v[u]) {//not w[u]
        CompletePack(dp, C, v[u], w[u]);
        return;
    }
    int a = 1;
    int cnt = d[u];
    while (a < cnt){
        SinglePack(dp, C, a*v[u], a*w[u]);
        cnt -= a;
        a <<= 1;
    }
    SinglePack(dp, C, cnt*v[u], cnt*w[u]);
}

signed main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m, C;
    cin >> n >> m >> C;
    item[0].resize(C+1); item[1].resize(C+1);

    for (int i = 1; i <= n; i++){
        cin >> v[i] >> w[i] >> d[i];
    }
//多重背包处理
    vector<int>& dp = item[0];
    for (int i = 1; i <= n; i++){
        MultiplePack(dp, C, i);
    }

    vector<int> ans(C+1), oldans = item[0];
    for (int i = 1; i <= m; i++){
        int a, b, c; cin >> a >> b >> c;

//泛化物品叠加
        vector<int>& it = item[1];
        for (int j = 0; j <= C; j++){
            it[j] = a*j*j + b*j + c;
            ans[j] = oldans[j];//假设不选第item[1]件物品，则直接继承
        }

        for (int ci = 0; ci <= C; ci++){
            for (int k = 0; k <= ci; k++){
                if (ans[ci] < oldans[k] + item[1][ci-k]) ans[ci] = oldans[k] + item[1][ci-k];
            }
        }
        swap(ans, oldans);
    }
    cout << oldans[C];
    return 0;
}