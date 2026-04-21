#include <bits/stdc++.h>
using namespace std;

int n, a, b;
vector<int> v;

int bfs() {
    queue<int> q;
    vector<int> dist(n+1, -1);
    dist[a] = 0;
    q.push(a);
    while (!q.empty())
    {
        int cur = q.front();
        if (cur == b) return dist[cur];
        q.pop();
        if (cur + v[cur] <= n && dist[cur + v[cur]] == -1) {
            dist[cur + v[cur]] = dist[cur] + 1;
            q.push(cur + v[cur]);
        }
        if (cur - v[cur] > 0 && dist[cur - v[cur]] == -1) {
            dist[cur - v[cur]] = dist[cur] + 1;
            q.push(cur - v[cur]);
        }
    }
    return -1;
}

int main() {
    cin >> n >> a >> b;
    v.resize(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    cout << bfs();
}