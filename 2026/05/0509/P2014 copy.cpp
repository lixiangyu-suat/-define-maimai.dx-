#include <bits/stdc++.h>
using namespace std;

int dp[302][302];// dp[u][j] 代表在 u 子树中选 j 门课的最大收益
vector<vector<int>> g;
vector<int> score;

void dfs(int u, int m){
    dp[u][1] = score[u]; dp[u][0] = 0;
    for (int v : g[u]){
        dfs(v, m);
        for (int j = m; j >= 1; j--){
            for (int k = 0; k < j; k++){
                if (dp[u][j-k] != -1 && dp[v][k] != -1){
                    dp[u][j] = max(dp[u][j], dp[u][j-k] + dp[v][k]);
                }
            }
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    memset(dp, 0, sizeof(dp));
    int n, m; cin >> n >> m;
    g.resize(n+1);
    score.resize(n+1);
    for (int i = 1; i <= n; i++){
        int u; cin >> u >> score[i];
        g[u].push_back(i);
    }
    dfs(0, m+1);
    cout << dp[0][m+1];
    return 0;
}