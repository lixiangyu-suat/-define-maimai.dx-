#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int endr, endc;
int ans = 0;
vector<vector<int>> grid;
vector<int> dx = {1,-1,0,0}, dy = {0,0,1,-1};

void dfs(int r, int c){
    if (r == endr && c == endc) {
        ans++;
        return;
    }
    for(int i = 0; i < 4; ++i) {
        int nx = r + dx[i], ny = c + dy[i];
        if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
        if (!grid[nx][ny]) {
            grid[nx][ny] = 1;
            dfs(nx, ny);
            grid[nx][ny] = 0;
        }
    }
}


int main() {
    cin >> n >> m >> t;
    grid.resize(n+1, vector<int>(m+1, 0));
    int sx, sy; cin >> sx >> sy >> endr >> endc;
    grid[sx][sy] = 1;
    while(t--){
        int r, c; cin >> r >> c;
        grid[r][c] = 1;
    }
    dfs(sx,sy);
    cout << ans << endl;
}