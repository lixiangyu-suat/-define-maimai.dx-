#include <bits/stdc++.h>
using namespace std;

const int MAXN = 12;
const int MAXM = 12;
bool wall[MAXN][MAXM];
bool used[MAXN][MAXM];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M, T;

int sum = 0;
void dfs(int x, int y, int tx, int ty){
    if (x == tx && y == ty){
        sum++;
        return;
    }
    for (int k = 0; k < 4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx > 0 && nx <= N && ny > 0 && ny <= M && !used[nx][ny] && !wall[nx][ny]){
            used[nx][ny] = true;
            dfs(nx, ny, tx, ty);
            used[nx][ny] = false;
        }
    }
}

int main(){
    
    cin >> N >> M >> T;
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    memset(wall, false, sizeof(wall));// 有后效性，只能暴力搜索
    memset(wall, false, sizeof(used));

    int x, y;
    for (int i = 0; i < T; i++){
        cin >> x >> y;
        wall[x][y] = true;
    }

    used[sx][sy] = true;
    dfs(sx, sy, tx, ty);
    used[sx][sy] = false;

    cout << sum;

    return 0;
}