#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
vector<vector<int>> grid;

struct node{
    int r, c;
};

vector<int> dx = {1,1,2,2,-1,-1,-2,-2}, dy = {2,-2,1,-1,2,-2,1,-1};

void bfs(){
    queue<node> q;
    grid[x][y] = 0;
    q.push({x,y});
    while(!q.empty()) {
        node cur = q.front();
        q.pop();
        for(int i = 0; i < 8; ++i) {
            int nx = cur.r + dx[i], ny = cur.c + dy[i];
            if (nx > 0 && ny > 0 && nx <= n && ny <= m && grid[nx][ny] == -1) {
                grid[nx][ny] = grid[cur.r][cur.c] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m >> x >> y;
    grid.resize(n+1, vector<int>(m+1, -1));
    bfs();
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}