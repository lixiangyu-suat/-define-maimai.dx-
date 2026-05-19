#include <bits/stdc++.h>
using namespace std;

int dp[302][302];
vector<vector<pair<int, int>>> g;
int dfs(int u, int k){
    if (k == 0 || g[u].empty()) {
        dp[u][k] = 0;
        return dp[u][k];
    }
    if (dp[u][k] != -1) return dp[u][k];
    for (auto [v, d] : g[u]){
        for (int i = k; i >= 1; i--){
            dp[u][i] = max(dp[u][i], dfs(v, i-1)+d);
        }
    }
    return dp[u][k];
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    memset(dp, -1, sizeof(dp));
    int n, m; cin >> n >> m;
    g.resize(n+1);
    for (int i = 1; i <= n; i++){
        int u, d; cin >> u >> d;
        g[u].push_back({i, d});
    }
    int ans = dfs(0, m);
    cout << ans;
}