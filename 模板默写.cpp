#include <bits/stdc++.h>
using namespace std;

/**
 * 💡 备忘录：
 * 1. 数组开大点 (N=2e5+10)，long long 必带。
 * 2. 字符串哈希：r = l + len - 1。
 * 3. 快速幂：while(n > 0)，n >>= 1。
 * 4. 判连通：edge_count == n - 1。
 */

#define int long long
#define pb push_back
#define fi first
#define se second
using ull = unsigned long long;
const int INF = 0x3f3f3f3f3f3f3f3fLL;
const int N = 200005; 

// --- 1. 并查集 (DSU) ---
struct DSU {
    vector<int> p;
    DSU(int n) { p.resize(n + 1); iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa == fb) return false;
        p[fa] = fb; return true;
    }
};

// --- 2. 快速幂 (QMI) ---
int qmi(int a, int n, int mod) {
    int res = 1 % mod; a %= mod;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// --- 3. Dijkstra (最短路) ---
struct Edge { int to, w; };
struct Node {
    int u, d;
    bool operator>(const Node& o) const { return d > o.d; }
};

vector<int> dijkstra(int start, int n, vector<Edge> adj[]) {
    vector<int> dist(n + 1, INF);
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    dist[start] = 0;
    pq.push({start, 0});
    while (!pq.empty()) {
        Node it = pq.top(); pq.pop();
        if (it.d > dist[it.u]) continue;
        for (auto& e : adj[it.u]) {
            if (dist[e.to] > it.d + e.w) {
                dist[e.to] = it.d + e.w;
                pq.push({e.to, dist[e.to]});
            }
        }
    }
    return dist;
}

// --- 4. 字符串哈希 (Hash) ---
ull h[N], p[N];
const ull P = 131;
void init_hash(const string& s) {
    p[0] = 1; h[0] = 0;
    for (int i = 1; i <= s.size(); i++) {
        h[i] = h[i - 1] * P + s[i - 1];
        p[i] = p[i - 1] * P;
    }
}
ull get_val(int l, int r) { // l, r 从 1 开始
    return h[r] - h[l - 1] * p[r - l + 1];
}

// --- 逻辑演示：在 s 中找 tar ---
int find_str(const string& s, const string& tar) {
    init_hash(s);
    ull tar_h = 0;
    for (char c : tar) tar_h = tar_h * P + c;
    int n = s.size(), m = tar.size();
    for (int i = 1; i <= n - m + 1; i++) {
        if (get_val(i, i + m - 1) == tar_h) return i - 1; // 返回 0-based 下标
    }
    return -1;
}

// --- 5. 组合数 ---
int c[5005][5005];
ull mod =1e9 + 7;
void init(){
    for(int i = 0; i < 5000; ++i){
        c[i][0] = 1;
        for(int j = 1; j <= i; ++j) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
        }
    }
}


// --- 6. 优先搜索 ---
vector<vector<int>> grid;
vector<bool> vis;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int target;
void dfs(int cur) {
    vis[cur] = 1;
    if (cur == target) return;
    for(auto i: grid[cur]) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs(i);
            // vis[i] = 0;
        }
    }
    return;
}

void bfs(int start) {
    queue<int> q;
    vector<int> dist(grid.size(), INF);
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto i : grid[cur]) {
            if (!vis[i]) {
                q.push(i);
                vis[i] = 1;
                dist[i] = dist[cur] + 1;
            }
        }
    } 
    return;
}



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // TODO;
    
    return 0;
}