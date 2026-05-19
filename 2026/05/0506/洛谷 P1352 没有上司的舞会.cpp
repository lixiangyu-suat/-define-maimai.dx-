#include <bits/stdc++.h>
using namespace std;

const int N = 6006;
int dp[N][2], a[N];
vector<vector<int>> son;
vector<int> p;

void dfs(int cur){
    if (son[cur].empty()){
        return;
    }

    int sum = 0;
    for (auto u : son[cur]){
        dfs(u);
    }
    int sum_0 = 0, sum_1 = 0;
    for (auto u : son[cur]){
        sum_0 += dp[u][0];//不选u的sum
        sum_1 += dp[u][1];
    }
    dp[cur][0] = max(sum_1, sum_0);
    dp[cur][1] = sum_0+a[cur];
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

    int n; cin >> n;
    memset(dp, 0, sizeof(dp));
    son.resize(n+1);
    p.resize(n+1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++){
        int cur, pa;
        cin >> cur >> pa;
        son[pa].push_back(cur);
        p[cur] = pa;
    }
    int cur = 1, root;
    while (p[cur] != 0) cur = p[cur];
    root = cur;

    dfs(root);
    cout << max(dp[root][0], dp[root][1]);
    return 0;
}