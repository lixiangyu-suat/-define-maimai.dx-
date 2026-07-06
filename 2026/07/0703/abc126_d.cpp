#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
bool vis[N];
int color[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(vis, false, sizeof(vis));
    int n;
    cin >> n;
    int u, v, d;
    vector<vector<pair<int, int>>> g(n+1);
    for (int i = 1; i < n; i++){
        cin >> u >> v >> d;
        d &= 1;
        g[u].push_back({v, d});
        g[v].push_back({u, d});
    }

    queue<int> q;
    q.push(1);
    color[1] = 0;

    while (q.size()){
        int u = q.front();
        q.pop();

        for (auto [v, d] : g[u]){
            if (!vis[v]){
                vis[v] = true;
                color[v] = d^color[u];
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        cout << color[i] << "\n";
    }
    return 0;
}