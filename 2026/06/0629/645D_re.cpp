#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e5+5;
int in_degree[N];
struct E{
    int u, v;
} edge[N];

bool check(int k){
    vector<vector<int>> adj(n+1);
    for (int i = 1; i <= n; i++) in_degree[i] = 0;
    for (int i = 1; i <= k; i++){
        int u = edge[i].u;
        int v = edge[i].v;
        adj[u].push_back(v);
        in_degree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) if (in_degree[i] == 0) q.push(i);
    while (!q.empty()){
        if (q.size() > 1) return false;
        int u = q.front();
        q.pop();
        for (auto v : adj[u]){
            in_degree[v]--;
            if (in_degree[v] == 0) q.push(v);
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> edge[i].u >> edge[i].v;
    }
    int ans = -1;
    int mid, l = 1, r = m;
    while (l <= r){
        mid = (r-l)/2 + l;
        if (check(mid)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans;
    return 0;
}