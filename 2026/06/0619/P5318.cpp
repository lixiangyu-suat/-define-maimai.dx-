#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
bool vis[N];

void bfs(vector<vector<int>>& g, int st){
    queue<int> q;
    q.push(st);
    
    while (!q.empty()){
        int cur = q.front();
        q.pop();

        if (cur != 1) cout << ' '; cout << cur;

        for (auto v : g[cur]){
            if (!vis[v]){
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

void dfs(vector<vector<int>>& g, int cur){
    if (cur != 1) cout << ' '; cout << cur;
    for (auto v : g[cur]){
        if (!vis[v]) {
            vis[v] = true;
            dfs(g, v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);
    int u, v;
    for (int i = 0; i < m; i++){
        cin >> u >> v;
        g[u].push_back(v);
    }

    for (int i = 1; i <= n; i++){
        sort(g[i].begin(), g[i].end());
    }


    memset(vis, false, sizeof(vis)); vis[1] = true;
    dfs(g, 1);
    cout << "\n";
    memset(vis, false, sizeof(vis)); vis[1] = true;
    bfs(g, 1);
    
    return 0;

}