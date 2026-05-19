#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;

int block[2][N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void change(int r, int c, int n) {
    set<int> color;
    for (int k = 0; k < 4; k++){
        int nx = r + dx[k];
        int ny = c + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || block[nx][ny] == 0) continue;
        color.insert(block[nx][ny]);
    }
    for (int i = 1; i <= 4; i++){
        if (!color.count(i)){
            block[r][c] = i;
            return;
        }
    }
}

signed main() {
    int n; cin >> n;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            cin >> block[i][j];
        }
    }
    if (n == 1) {
        if (block[0][0] == 0) block[0][0] = 1;
        else{
            block[1][0] = 1;
        }
    }
    else {
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < n; j++){
                if (block[i][j] == 0 )
                change(i, j ,n);
            }
        }
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            cout << block[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}